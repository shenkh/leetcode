// 75SortColors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/sort-colors
Given an array with n objects colored red, white or blue,
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/


class Solution {
public:
#if 0
	void sortColors(vector<int>& nums) {
		//bubble sort
		int length = nums.size();
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = length - 1; j > i; j--)
			{
				if (nums[i] > nums[j])
					swap(nums[i], nums[j]);
			}
		}
}
#else
	void sortColors(vector<int>& nums) {
		//The idea is to sweep all 0s to the left and all 2s to the right, then all 1s are left in the middle.
		//https://leetcode.com/problems/sort-colors/discuss/26472/Share-my-at-most-two-pass-constant-space-10-line-solution
		int zero = 0, second = nums.size() - 1;
		for (int i = 0; i <= second; i++)
		{
			while (nums[i] == 2 && i < second) swap(nums[i], nums[second--]);
			while (nums[i] == 0 && i > zero) swap(nums[i], nums[zero++]);
		}
	}
#endif // 0
};

int main()
{
	Solution sln;
	vector<int> nums{ 2,0,2,1,1,0 };
	sln.sortColors(nums);
	for (auto & i : nums)
		cout << i << " ";
	std::cout << "Hello World!\n";
}
