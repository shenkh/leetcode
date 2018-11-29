// 416PartitionEqualSubsetSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

/*https://leetcode.com/problems/partition-equal-subset-sum/
Given a non-empty array containing only positive integers,
find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.*/

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 1)
			return false;

		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		//只需找到所有元素和的一半 对应的组合即可
		sum /= 2;

		//dp[i][j]表示当前数组中的前i个元素是否能组成和为j
		vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1));

		dp[0][0] = true;

		for (int i = 1; i < nums.size() + 1; i++) {
			dp[i][0] = true;
		}

		for (int j = 1; j < sum + 1; j++) {
			dp[0][j] = false;
		}

		for (int i = 1; i < nums.size() + 1; i++)
		{
			for (int j = 1; j < sum + 1; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j - nums[i - 1] >= 0)
					dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
			}
		}

		return dp[nums.size()][sum];
	}
};

class Solution2 {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 1)
			return false;

		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		//只需找到所有元素和的一半 对应的组合即可
		sum /= 2;

		//dp[i]表示当前数组中是否有相应的组合的和的值为i
		vector<int> dp(sum + 1, false);

		dp[0] = true;

		for (size_t i = 0; i < nums.size(); i++)
		{
			//注意这里是反向
			for (int j = sum; j > 0; j--)
				if (j >= nums[i])
					dp[j] = dp[j] || dp[j - nums[i]];
		}

		return dp[sum];
	}
};

//Time Limits Exceeded
class Solution3 {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 1)
			return false;

		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		//只需找到所有元素和的一半 对应的组合即可
		sum /= 2;

		int result = DFS(nums, sum, 0);
		return result;
	}

private:
	int DFS(vector<int>& nums, int remain, int start) {
		if (start == nums.size())
			return remain == 0 ? 1 : 0;

		if (remain < 0)
			return 0;

		return DFS(nums, remain - nums[start], start + 1)
			+ DFS(nums, remain, start + 1);
	}
};

int main()
{
	Solution3 sln;
	vector<int> testcase{ 1, 5, 11, 5 };
	cout << sln.canPartition(testcase) << endl;
	std::cout << "Hello World!\n";
}
