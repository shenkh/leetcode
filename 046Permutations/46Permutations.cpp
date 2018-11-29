// 46Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*https://leetcode.com/problems/permutations/
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> p;
		vector<bool> element_used(nums.size(), false);
		backtracking(nums, res, p, element_used);
		return res;
	}

private:
	void backtracking(vector<int>&nums, vector<vector<int>> &res, vector<int> &p, vector<bool>& element_used)
	{
		if (p.size() == nums.size())
		{
			res.push_back(p);
			return;
		}
		else
		{
			for (size_t i = 0; i < nums.size(); i++)
			{
				//如果该元素已经被添加进了p中，则跳过
				if (element_used[i]) continue;

				p.push_back(nums[i]);
				element_used[i] = true;
				backtracking(nums,res, p, element_used);
				p.pop_back();
				element_used[i] = false;
			}
		}
	}

public:
	//另外一种全排列的方法。每个值和后面每个值交换
	void swap_two(vector<vector<int>> &ans, vector<int>&nums, int start) {
		if (start == nums.size())
		{
			ans.push_back(nums);
			return;
		}
		else
		{
			for (size_t i = start; i < nums.size(); i++)
			{
				swap(nums[start], nums[i]);
				swap_two(ans, nums, start + 1);
				swap(nums[start], nums[i]);
			}
		}
	}
};

int main()
{
	Solution sln;
	vector<int> test_case{ 1,2,3 };
	vector<vector<int> > ans = sln.permute(test_case);
	for (const auto & i : ans)
	{
		for (const auto & j : i)
			cout << j << ' ';
		cout << endl;
	}
	ans.clear();
	cout << endl;

	sln.swap_two(ans, test_case, 0);
	for (const auto & i : ans)
	{
		for (const auto & j : i)
			cout << j << ' ';
		cout << endl;
	}
	std::cout << "Hello World!\n";
}
