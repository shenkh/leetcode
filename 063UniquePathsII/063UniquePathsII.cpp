// 063UniquePathsII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/unique-paths-ii/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
	Input:
	[
	  [0,0,0],
	  [0,1,0],
	  [0,0,0]
	]
	Output: 2
	Explanation:
	There is one obstacle in the middle of the 3x3 grid above.
	There are two ways to reach the bottom-right corner:
	1. Right -> Right -> Down -> Down
	2. Down -> Down -> Right -> Right*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int r = obstacleGrid.size();
		if (r == 0) return 0;
		int c = obstacleGrid[0].size();

		if (obstacleGrid[0][0] == 1) return 0;
		vector<vector<int>> dp(r, vector<int>(c, 0));
		dp[0][0] = 1;

		//±ß½ç×´Ì¬³õÊ¼»¯
		for (int i = 1; i < r; ++i)
			if (dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0)
				dp[i][0] = 1;

		for (int j = 1; j < c; ++j)
			if (dp[0][j - 1] == 1 && obstacleGrid[0][j] == 0)
				dp[0][j] = 1;

		for (int i = 1; i < r; ++i)
			for (int j = 1; j < c; ++j) {
				if (obstacleGrid[i][j] == 0)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				else
					dp[i][j] = 0;
			}

		return dp[r - 1][c - 1];
	}
};

int main()
{
	Solution sln;
	vector<vector<int>> testcase{ {0,0,0},{0,1,0},{0,0,0} };
	cout << sln.uniquePathsWithObstacles(testcase) << endl;
	std::cout << "Hello World!\n";
}
