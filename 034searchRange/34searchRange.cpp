// 34searchRange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		vector<int> ans{ -1, -1 };
		//注意如果判断条件不取等，right=mid,
		//如果取等,right初始化时int right = nums.size()-1，同时更新时right=mid-1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;

			if (nums[mid] < target)
				left = mid + 1;

			else if (nums[mid] > target)
				right = mid;
			else
			{
				left = mid;
				right = mid;

				//找到了target，则往左往右判断下是否还有值为target的。
				while ((left - 1) >= 0 && nums[left - 1] == target)
					left--;

				while ((right + 1) < nums.size() && nums[right + 1] == target)
					right++;

				ans[0] = left;
				ans[1] = right;
				break;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sln;
	vector<int> test_case{ 5,7,7,8,8,10 };
	vector<int> ans = sln.searchRange(test_case, 3);
	for (const auto & i : ans)
		cout << i << endl;

	std::cout << "Hello World!\n";
}
