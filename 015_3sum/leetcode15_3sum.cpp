// leetcode15_3sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*https://leetcode.com/problems/3sum/
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());   //首先排序
		vector<vector<int> > result;

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				break;

			int target = -nums[i];	//寻找和等于target的另外两个数，构成triplet
			int front = i + 1;			//从两个端点开始搜索
			int back = nums.size() - 1;
			while (front < back)
			{
				int sum = nums[front] + nums[back];
				if (sum < target)
					front++;
				else if (sum > target)
					back--;
				else
				{
					vector<int> triplet{ nums[i], nums[front], nums[back] };
					result.push_back(triplet);

					while (front < back && nums[front] == triplet[1])  //处理重复的triplet[1]
						front++;

					while (front < back && nums[back] == triplet[2])  //处理重复的triplet[2]
						back--;
				}
			}

			while (nums[i] == nums[i + 1] && (i + 1) < nums.size())  //处理重复的triplet[0]
				i++;
		}
		return result;
	}
};


int main()
{
	std::cout << "Hello World!\n";
}
