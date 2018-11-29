// leetcode1TwoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<map>
using namespace std;

/*https://leetcode.com/problems/two-sum/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> hashtable;  //key是nums的值，value是nums对应的index

		for (size_t i = 0; i < nums.size(); i++)
		{
			auto iter = hashtable.find(nums[i]);
			if (iter == hashtable.end())
				hashtable[nums[i]] = i;
		}

		vector<int> result(2);
		for (size_t i = 0; i < nums.size(); i++)
		{
			auto iter = hashtable.find(target - nums[i]);
			if (iter != hashtable.end() && iter->second != i)  //排除自身加自身等于target的情况
			{
				result[0] = i;
				result[1] = iter->second;
				break;
			}
		}
		return result;
	}
};

int main()
{
	vector<int> input{ 2,7,11,15 };
	Solution leetcode1;
	vector<int> ans = leetcode1.twoSum(input, 9);
	for (const auto & s : ans)
		cout << s << " ";
	cout << endl;
	std::cout << "Hello World!\n";
}
