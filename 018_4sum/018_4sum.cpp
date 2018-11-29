// 018_4sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/4sum/
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		vector<int> single;

		DFS(nums, res, single, 0, target, 4);
		return res;
	}

private:
	void DFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& single, int start, int remain, int four_num) {
		if (four_num == 0) {
			if (remain == 0) res.push_back(single);
			return;
		}

		for (int i = start; i < nums.size() && four_num > 0; i++) {
			single.push_back(nums[i]);
			DFS(nums, res, single, i, remain - nums[i], four_num - 1);
			single.pop_back();
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> testcase{ 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> res;
	res = sln.fourSum(testcase, 0);
	for (auto vec : res) {
		for (auto i : vec) {
			cout << i << ",";
		}
		cout << endl;
	}

	return 0;
}
