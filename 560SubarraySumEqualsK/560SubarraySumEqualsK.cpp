// 560SubarraySumEqualsK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*https://leetcode.com/problems/subarray-sum-equals-k/
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].*/

//Using Cummulative sum
class Solution1 {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;

		int res = 0;
		vector<int> sum(nums.size() + 1);
		sum[0] = 0;
		for (int i = 0; i < nums.size(); i++)
			sum[i + 1] = sum[i] + nums[i];

		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j <= nums.size(); j++)
				if (sum[j] - sum[i] == k)
					res++;

		return res;
	}
};

//https://leetcode.com/problems/subarray-sum-equals-k/solution/
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;

		int res = 0;
		//key：表示的是前n个元素的和sum，value：表示的是这个和出现过的次数
		unordered_map<int, int> sum_counts;

		//sum表示的是前n个元素的和
		int sum = 0;
		//注意:和为0的次数要初始化为1次
		sum_counts[sum]++;

		for (const auto & n : nums) {
			sum += n;
			auto iter = sum_counts.find(sum - k);
			if (iter != sum_counts.end())
				res += iter->second;
			sum_counts[sum]++;
		}

		return res;
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 1,1,1 };
	cout << sln.subarraySum(testcase, 2) << endl;
	std::cout << "Hello World!\n";
}
