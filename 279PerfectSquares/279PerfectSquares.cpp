// 279PerfectSquares.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<limits>
using std::min;
using std::vector;

/*https://leetcode.com/problems/perfect-squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.*/

class Solution {
public:
	int numSquares(int n) {
		//dp保存的是该数值所需的perfect square numbers的个数。
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;

		for (int i = 1; i <= n; i++)
		{
			// For each i, it must be the sum of some number (i - j*j) and 
			// a perfect square number (j*j).
			for (int j = 1; j*j <= i; j++)
				dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		return dp.back();
	}
};
int main()
{
	Solution sln;
	std::cout << sln.numSquares(12) << std::endl;
	std::cout << "Hello World!\n";
}
