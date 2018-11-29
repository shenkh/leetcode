// 121BestTimeToBuyAndSellStock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<limits>
using namespace std;

/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
			 Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;

		int maxprofit = 0;
		//µ±Ç°²¨¹È
		int minval = INT_MAX;

		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minval)
				minval = prices[i];
			else if (maxprofit < prices[i] - minval)
				maxprofit = prices[i] - minval;
		}
		return maxprofit;
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 7,1,5,3,6,4 };
	cout << sln.maxProfit(testcase) << endl;
	std::cout << "Hello World!\n";
}
