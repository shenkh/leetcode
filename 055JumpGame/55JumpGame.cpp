// 55JumpGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/jump-game/
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.*/

class Solution {
public:
#if 0
	bool canJump(vector<int>& nums) {
		int i = 0;
		if (nums.size() < 1)
			return false;

		while (i < nums.size() - 1)
		{
			if (nums[i] == 0)
				break;

			vector<int> greed;
			for (size_t j = 1; j <= nums[i]; j++)
			{
				if (i + j >= nums.size())
					return true;
				else
					greed.push_back(nums[i + j] + j);
			}

			auto iter = max_element(greed.begin(), greed.end());
			i = i + 1 + distance(greed.begin(), iter);
			cout << nums[i] << endl;
		}
		if (i >= nums.size() - 1)
			return true;
		else
			return false;
}
#endif // 0

#if 0
	bool canJump(vector<int>& nums) {

		int length = nums.size();
		int last_pos = length - 1;

		for (int i = length - 1; i >= 0; i--)
		{
			if (i + nums[i] >= last_pos)
				last_pos = i;
		}
		return last_pos == 0;
	}
#endif // 0


	//just iterate and update the maximal index that  can reach
	bool canJump(vector<int>& nums) {
		int length = nums.size();
		int i = 0;
		for (int reach = 0; i < length && i <= reach; i++)
			reach = max(nums[i] + i, reach);
		return i == length;
	}

};

int main()
{
	Solution sln;
	vector<int> test_case{ 2,3,1,0,4 };
	std::cout << sln.canJump(test_case) << endl;
	std::cout << "Hello World!\n";
}
