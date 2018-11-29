// 53MaximumSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

/*https://leetcode.com/problems/maximum-subarray/
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach,
which is more subtle.*/

class Solution {
public:
#if 0
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums);

		for (size_t i = 1; i < nums.size(); i++)
			dp[i] += dp[i - 1];

		int max;
		if (nums.size() > 0)
			max = nums[0];

		//循环所有的起点
		for (size_t i = 0; i < nums.size(); i++)
		{
			//循环所有可能的终点
			for (size_t j = i; j < nums.size(); j++)
			{
				int tmp = dp[j] - dp[i] + nums[i];
				if (tmp > max)
					max = tmp;
			}
		}
		return max;
	}
#else // 0
	int maxSubArray(vector<int>& nums) {

		vector<int> dp(nums.size());
		int maxVal;
		if (nums.size() > 0)
			dp[0] = nums[0];

		//循环所有的终点
		for (size_t i = 1; i < nums.size(); i++)
		{
			//max(dp[i - 1], 0)
			dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
		}

		auto iter = max_element(dp.begin(), dp.end());
		maxVal = *iter;
		return maxVal;
	}
#endif
};

int main()
{
	Solution sln;
	vector<int> test_case{ -2,1,-3,4,-1,2,1,-5,4 };
	std::cout << sln.maxSubArray(test_case) << endl;
	std::cout << "Hello World!\n";
}
