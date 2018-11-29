// 213HouseRobberII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*https://leetcode.com/problems/house-robber-ii/
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
			 because they are adjacent houses.

Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
			 Total amount you can rob = 1 + 3 = 4.*/


class Solution {
public:
	int rob(vector<int>& nums) {
		int length = nums.size();
		if (length == 0)
			return 0;
		else if (length == 1)
			return nums[0];

		//dp[i]表示的是在前面i家所能获得的最大值。包括i。排除最后一家。
		vector<int> dp(nums.size());

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for (size_t i = 2; i < length - 1; i++)
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

		int ans = dp[length - 2];

		//dp[i]表示的是后面i家所能获得的最大值。包括i。排除第一家。
		dp[length - 1] = nums.back();
		dp[length - 2] = max(nums[length - 1], nums[length - 2]);

		for (int i = length - 3; i > 0; i--)
			dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);

		return max(ans, dp[1]);
	}
};

/*class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if(size == 0)
			return 0;
		if(size == 1)
			return nums[0];
		int pre = 0, cur = 0;
		for(int i = 0; i < size-1; i++)
		{
			int temp = pre;
			pre = cur;
			cur = max(pre, temp + nums[i]);
		}
		int pre1 = 0, cur1 = 0;
		for(int i = 1; i < size; i++)
		{
			int temp = pre1;
			pre1= cur1;
			cur1 = max(pre1, temp + nums[i]);
		}
		return max(cur, cur1);
	}
};*/

int main()
{
	Solution sln;
	vector<int> testcase{ 3 };
	cout << sln.rob(testcase) << endl;
	std::cout << "Hello World!\n";
}
