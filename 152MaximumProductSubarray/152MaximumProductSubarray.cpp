// 152MaximumProductSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/maximum-product-subarray
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> dp(nums.size());
		if (nums.size() > 0)
			dp[0] = nums[0];

		for (size_t i = 1; i < nums.size(); i++)
		{
			if (dp[i - 1] == 0)
				dp[i] = nums[i];
			else
				dp[i] = dp[i - 1] * nums[i];
		}

		//·´Ðò¼ÆËã
		vector<int> dpr(nums.size());
		dpr[nums.size() - 1] = nums.back();

		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (dpr[i + 1] == 0)
				dpr[i] = nums[i];
			else
				dpr[i] = dpr[i + 1] * nums[i];
		}
		return max(*max_element(dp.begin(), dp.end()),
			*max_element(dpr.begin(), dpr.end()));

	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 3,-1,4 };
	cout << sln.maxProduct(testcase) << endl;
	std::cout << "Hello World!\n";
}
