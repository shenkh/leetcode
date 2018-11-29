// 047PermutationsII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/permutations-ii/
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]*/

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
			return res;

		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		vector<int> p;
		backtracking(nums, res, p, used);

		return res;
	}

private:
	void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& p, vector<bool>& used) {
		if (p.size() == nums.size()) {
			res.push_back(p);
			return;
		}

		for (int i = 0; i < nums.size(); ) {
			//nums[i]已经加入到p中， 则跳过
			if (used[i]) {
				++i;
				continue;
			}

			p.push_back(nums[i]);
			used[i] = true;
			backtracking(nums, res, p, used);
			p.pop_back();
			used[i] = false;

			//跳过重复的元素
			while (++i < nums.size() && nums[i] == nums[i - 1])
				continue;
		}
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 1,1,2,2,2,2,2,2,2,2 };
	vector<vector<int>> res;
	res = sln.permuteUnique(testcase);
	for (auto vec : res) {
		for (auto i : vec)
			cout << i << " ";
		cout << endl;
	}
	std::cout << "Hello World!\n";
}
