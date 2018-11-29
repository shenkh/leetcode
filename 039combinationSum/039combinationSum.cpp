// 039combinationSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

/*https://leetcode.com/problems/combination-sum/
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]*/

class Solution {
public:
	void backtracking(vector<vector<int>> &ans, vector<int>& candidates, vector<int>& p, int remain, int start)
	{
		if (remain == 0)
		{
			ans.push_back(p);
			return;
		}
		else if (remain < 0)
			return;
		else
		{
			for (size_t i = start; i < candidates.size(); i++)
			{
				//cout << candidates[i] << endl;
				p.push_back(candidates[i]);
				backtracking(ans, candidates, p, remain - candidates[i], i);  // not i + 1 because we can reuse same elements
				p.pop_back();
			}
		}
	}

	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> p;
		backtracking(ans, candidates, p, target, 0);
		return ans;
	}
};

int main()
{
	Solution sln;
	vector<int> test_case{ 2,3,6,7 };
	vector<vector<int> > ans = sln.combinationSum(test_case, 7);

	std::cout << "Hello World!\n";
}
