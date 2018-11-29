// 64MinimumPathSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/minimum-path-sum
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		size_t r = grid.size();
		size_t c = grid[0].size();
		if (r < 1 || c < 1)
		{
			throw "invalid parameter, the row and the col needs to be larger than 0";
		}
		vector<vector<int>> dp(grid);
		for (size_t i = 1; i < r; i++)
			dp[i][0] += dp[i - 1][0];

		for (size_t j = 1; j < c; j++)
			dp[0][j] += dp[0][j - 1];

		for (size_t i = 1; i < r; i++)
			for (size_t j = 1; j < c; j++)
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

		return dp[r - 1][c - 1];
	}
};

int main()
{
	Solution sln;
	vector<vector<int>> grid{ {1,3,1},{1,5,1},{4,2,1} };
	try
	{
		cout << sln.minPathSum(grid);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	std::cout << "Hello World!\n";
}
