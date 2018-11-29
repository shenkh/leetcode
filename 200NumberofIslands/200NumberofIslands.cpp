// 200NumberofIslands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/number-of-islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3*/

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		r = grid.size();
		if (r == 0) return 0;
		c = grid[0].size();

		int count = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (grid[i][j] == '1') {
					DFS(grid, i, j);
					count++;
				}
			}
		}
		return count;
	}
private:
	int r;  //输入数据的行
	int c;  //输入数据的列

	void DFS(vector<vector<char>>& grid, int i, int j) {
		if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == '0')
			return;
		grid[i][j] = '0';
		DFS(grid, i - 1, j);
		DFS(grid, i, j - 1);
		DFS(grid, i + 1, j);
		DFS(grid, i, j + 1);
		return;
	}
};


int main()
{
	Solution sln;
	vector<vector<char>> testcase{ {'1','1','1','1','0'},{'1','1','0','1','0'},
	{'1','1','0','0','0'},{'0','0','0','0','0'} };
	cout << sln.numIslands(testcase) << endl;
	std::cout << "Hello World!\n";
}
