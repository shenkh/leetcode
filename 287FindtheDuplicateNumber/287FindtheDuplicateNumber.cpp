// 287FindtheDuplicateNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*https://leetcode.com/problems/find-the-duplicate-number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist.
Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.*/

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		unordered_map<int, int> valuenum;
		for (size_t i = 0; i < nums.size(); i++)
		{
			auto iter = valuenum.find(nums[i]);
			if (iter != valuenum.end())
				return iter->first;
			else
				valuenum[nums[i]]++;
		}
		return -1;
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 3,1,3,4,2,3 };
	cout << sln.findDuplicate(testcase) << endl;
	std::cout << "Hello World!\n";
}
