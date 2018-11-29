// 283MoveZeroes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/move-zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int length = nums.size();
		if (length <= 0)
			return;

		int lastNonZeroAt = 0;

		//将所有的非零值往前移动
		for (int i = 0; i < length; i++)
		{
			if (nums[i] != 0)
				nums[lastNonZeroAt++] = nums[i];
		}
		for (; lastNonZeroAt < length; lastNonZeroAt++)
			nums[lastNonZeroAt] = 0;
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 0,1,0,3,4,5 };
	sln.moveZeroes(testcase);
	for (auto const & s : testcase)
		cout << s << " ";
	cout << endl;
	std::cout << "Hello World!\n";
}
