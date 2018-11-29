// 581ShortestUnsortedContinuousSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

/*https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.*/

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> sorted_nums(nums);
		sort(sorted_nums.begin(), sorted_nums.end());
		int left = nums.size(), right = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != sorted_nums[i]) {
				left = min(left, i);
				right = max(right, i);
			}
		}
		return right - left > 0 ? (right - left + 1) : 0;
	}
};

//Time Limit Exceeded
class Solution2 {
public:
	int findUnsortedSubarray(vector<int>& nums)
	{
		int left = nums.size(), right = 0;

		//selective sort
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] > nums[j]) {
					left = min(left, i);
					right = max(right, j);
				}
			}
		}
		return right - left > 0 ? (right - left + 1) : 0;
	}
};

class Solution3 {
public:
	int findUnsortedSubarray(vector<int>& nums)
	{
		int left = nums.size(), right = 0;

		//保存的是有序序列的序号
		stack<int> index;
		for (int i = 0; i < nums.size(); i++) {
			while (!index.empty() && nums[index.top()] > nums[i]) {
				left = min(left, index.top());
				index.pop();
			}
			index.push(i);
		}
		stack<int> indexreverse;
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!indexreverse.empty() && nums[indexreverse.top()] < nums[i])
			{
				right = max(right, indexreverse.top());
				indexreverse.pop();
			}
			indexreverse.push(i);
		}

		return right - left > 0 ? (right - left + 1) : 0;
	}
};

int main()
{
	Solution3 sln;
	vector<int> testcase{ 1,3,4,3,5,3,2 };
	cout << sln.findUnsortedSubarray(testcase) << endl;
	std::cout << "Hello World!\n";
}
