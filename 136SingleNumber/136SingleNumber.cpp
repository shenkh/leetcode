// 136SingleNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<map>
using namespace std;

/*https://leetcode.com/problems/single-number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> table;
		for (size_t i = 0; i < nums.size(); i++)
		{
			table[nums[i]] ++;
			if (table[nums[i]] == 2)
				table.erase(nums[i]);
		}
		return table.begin()->first;
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 4,1,2,1,2 };
	cout << sln.singleNumber(testcase) << endl;
	std::cout << "Hello World!\n";
}
