// 16threeSumClosest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/3sum-closest/
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int closest = nums[0] + nums[1] + nums[2] - target;

		int j, k, tmp;
		for (size_t i = 0; i < nums.size() - 2; i++)
		{
			j = i + 1;
			k = nums.size() - 1;
			while (j < k)
			{
				tmp = nums[i] + nums[j] + nums[k] - target;
				if (std::abs(tmp) < std::abs(closest))
					closest = tmp;

				if (tmp < 0)
					j++;
				else if (tmp > 0)
					k--;
				else
					return closest + target;
			}
		}
		return closest + target;
	}
};
int main()
{
	vector<int> test{ -1, 2, 1, -4 };
	Solution sln;
	cout << sln.threeSumClosest(test, 1) << endl;
    std::cout << "Hello World!\n"; 
}
