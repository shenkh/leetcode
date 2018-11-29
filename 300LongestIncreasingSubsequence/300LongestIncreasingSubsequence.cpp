// 300LongestIncreasingSubsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/longest-increasing-subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n^2) complexity.*/

//https://leetcode.com/problems/longest-increasing-subsequence/solution/

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int length = nums.size();
		if (length == 0)
			return 0;

		//dp表示的是当前位置下最长序列的值
		vector<int> dp(length, 0);
		dp[0] = 1;
		for (int i = 1; i < length; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j]);
			}
			//加上本身所占的个数1
			dp[i] += 1;
		}
		return *max_element(dp.begin(), dp.end());
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 10,9,2,5,3,7,101,18 };
	cout << sln.lengthOfLIS(testcase) << endl;
	std::cout << "Hello World!\n";
}
