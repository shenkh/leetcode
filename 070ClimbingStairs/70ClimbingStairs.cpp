// 70ClimbingStairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/climbing-stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step*/

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0)
			throw "Invalid parameter!";


#if 0
		int ans = 0;
		backtracking(n, ans);
		return ans;
#else
		if (n == 1)
			return 1;

		vector<int> dp(n + 1);
		dp[1] = 1, dp[2] = 2;
		for (int i = 3; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
#endif
	}
private:
	void backtracking(int &remain, int &ans) {
		if (remain == 0)
		{
			ans++;
			return;
		}
		else if (remain < 0)
			return;
		else
		{
			//只可能一步或者两步
			for (size_t i = 1; i <= 2; i++)
			{
				remain -= i;
				backtracking(remain, ans);
				remain += i;
			}
		}
	}
};

int main()
{
	Solution sln;
	try
	{
		std::cout << sln.climbStairs(1) << std::endl;
	}
	catch (const char * msg)
	{
		std::cout << "error occurred! " << msg << std::endl;
	}
	std::cout << "Hello World!\n";
}
