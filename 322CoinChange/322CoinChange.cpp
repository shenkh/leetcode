// 322CoinChange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

/*https://leetcode.com/problems/coin-change
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.*/

#if 0
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		int fewestcoin = INT_MAX;
		vector<int> tmp;
		backtracking(coins, tmp, fewestcoin, 0, amount);
		if (fewestcoin == INT_MAX)
			return -1;
		else
			return fewestcoin;
	}

private:
	void backtracking(vector<int> &coins, vector<int> &p, int &fewestcoin, int start, int remain)
	{
		if (remain == 0) {
			if (p.size() < fewestcoin)
				fewestcoin = p.size();
			return;
		}
		else if (remain < 0) {
			return;
		}
		else {
			for (int i = start; i < coins.size(); i++) {
				p.push_back(coins[i]);
				backtracking(coins, p, fewestcoin, i, remain - coins[i]);
				p.pop_back();
			}
		}
	}
};
#else

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		//注意，dp的初值不要设置为INT_MAX, 因为这样会导致dp[i - coins[j]] + 1可能变成负数
		//会影响min(dp[i], dp[i - coins[j]] + 1)的结果
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		//计算amount_ = 1,2,3....amount时所需的最少的coins的个数
		for (int i = 1; i <= amount; i++)
			for (int j = 0; j < coins.size(); j++)
			{
				if (coins[j] <= i)
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};
#endif



int main()
{
	Solution sln;
	vector<int> testcase{ 271,5,343,254,112 };
	cout << sln.coinChange(testcase, 4853) << endl;
	std::cout << "Hello World!\n";
}
