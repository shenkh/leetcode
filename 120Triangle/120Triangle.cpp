// 120Triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/triangle/
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
	 [2],
	[3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.*/

//recurse as binary tree
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		helper(triangle, 0, 0, 0);
		return res;
	}

private:
	int res = INT_MAX;
	void helper(vector<vector<int>>& triangle, int min_total, int row, int col) {
		if (row == triangle.size())
		{
			res = min_total < res ? min_total : res;
			return;
		}

		helper(triangle, min_total + triangle[row][col], row + 1, col);
		helper(triangle, min_total + triangle[row][col], row + 1, col + 1);
	}
};

//https://leetcode.com/problems/triangle/discuss/38730/DP-Solution-for-Triangle
class Solution2 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int res = 0;
		if (triangle.size() == 0)
			return 0;

		//用triangle最后一行初始化DP
		vector<int> dp(triangle.back());
		//Bottom-up
		for (int r = triangle.size() - 2; r >= 0; r--) {
			for (int c = 0; c < triangle[r].size(); c++) {
				dp[c] = min(dp[c], dp[c + 1]) + triangle[r][c];
			}
		}
		return dp[0];
	}
};

int main()
{
	Solution sln;
	vector<vector<int>> testcase{ {2},{3,4}, {6,5,7}, {4,1,8,3} };
	cout << sln.minimumTotal(testcase) << endl;
	std::cout << "Hello World!\n";
}
