// 62UniquePaths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

/*https://leetcode.com/problems/unique-paths/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?*/

class Solution {
public:
	int uniquePaths(int m, int n) {

		/*int rows = 100;
		int cols = 200;
		vector< vector<int> > f(rows, vector<int>(cols));
		f[rows - 1][cols - 1] = 0; // use it like arrays*/
		if (m < 1 || n < 1)
			throw "the parameter is invalid!";

		int ** dp = new int*[m];
		for (int i = 0; i < m; i++) //每一行 new一个n列的数组
			dp[i] = new int[n];

		for (int i = 0; i < m; i++)
			dp[i][0] = 1;
		for (int j = 0; j < n; j++)
			dp[0][j] = 1;

		for (int r = 1; r < m; r++)
			for (int c = 1; c < n; c++)
				dp[r][c] = dp[r - 1][c] + dp[r][c - 1];

		int ans = dp[m - 1][n - 1];
		for (int i = 0; i < m; i++)
			delete[] dp[i];
		delete[] dp;

		return ans;
	}
};

int main()
{
	Solution sln;
	try
	{
		cout << sln.uniquePaths(1, 1) << endl;
	}
	catch (const char* msg)
	{
		cout << "error occured! " << msg << endl;
	}
	std::cout << "Hello World!\n";
}
