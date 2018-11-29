// 78Subsets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> p;
		vector<vector<int>> ans;
		backtracking(ans, p, nums, 0);
		return ans;
	}
private:
	void backtracking(vector<vector<int>>& ans, vector<int>& p, vector<int>& nums, int start) {
		ans.push_back(p);
		for (size_t i = start; i < nums.size(); i++)
		{
			p.push_back(nums[i]);
			backtracking(ans, p, nums, i + 1);
			p.pop_back();
		}
	}
};

int main()
{
	Solution sln;
	vector<int> test_case{ 1,2,3 };
	vector<vector<int>> ans;
	ans = sln.subsets(test_case);
	for (auto const & i : ans)
	{
		for (auto const & j : i)
			cout << j << " ";
		cout << endl;
	}
	std::cout << "Hello World!\n";
}
