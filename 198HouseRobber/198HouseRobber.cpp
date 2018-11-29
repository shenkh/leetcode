// 198HouseRobber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*https://leetcode.com/problems/house-robber
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is
that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
			 Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
			 Total amount you can rob = 2 + 9 + 1 = 12.*/

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> dp(nums.size());
		if (nums.size() < 1)
			return 0;
		else if (nums.size() < 2)
			return nums[0];

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (size_t i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
		//return *max_element(dp.begin(), dp.end());
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 2,7,1,1,19 };
	cout << sln.rob(testcase) << endl;
	std::cout << "2018-12-15.Hello World!\n";
}
