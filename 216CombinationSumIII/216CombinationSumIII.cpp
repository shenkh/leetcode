// 216CombinationSumIII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/combination-sum-iii/
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]*/

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> single;
		backtracking(k, res, single, 1, n);
		return res;
	}

private:
	void backtracking(int k, vector<vector<int>>& res, vector<int>& single, int start, int remain) {
		if (remain < 0 || k < 0) {
			return;
		}
		else if (k == 0 && remain == 0) {
			res.push_back(single);
			return;
		}

		//{1,2,3....,8,9}
		for (int i = start; i <= 9; i++)
		{
			single.push_back(i);
			backtracking(k - 1, res, single, i + 1, remain - i);
			single.pop_back();
		}
	}
};

int main()
{
	Solution sln;
	vector<vector<int>> res = sln.combinationSum3(3, 9);
	for (auto vec : res) {
		for (auto i : vec)
			cout << i << " ";
		cout << endl;
	}
	std::cout << "Hello World!\n";
}
