// 338CountingBits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/counting-bits/
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
calculate the number of 1's in their binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]

Example 2:
Input: 5
Output: [0,1,1,2,1,2]

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.*/

/*Hint1:
You should make use of what you have produced already.
Hint2:
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Hint3:
Or does the odd/even status of the number help you in calculating the number of 1s?*/

#if 0
class Solution {
public:
	vector<int> countBits(int num) {
		if (num == 0)
			return vector<int>{0};

		//dp[i]表示数值i二进制表示时'1'的个数。
		vector<int> dp(num + 1);
		dp[0] = 0;
		dp[1] = 1;

		//Hint2:Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on.
		//划分为[2-3], [4-7],[8-15]是因为这些范围内的元素的二进制长度是相同的(头部是1)。
		for (int i = 2; i <= num; i *= 2)
		{
			int begin = 0;
			for (int j = i; j < i * 2 && j <= num; j++)
			{
				//Hint1:You should make use of what you have produced already.
				dp[j] = 1 + dp[begin++];
			}
		}
		return dp;
	}
};
#endif // 0


class Solution {
public:
	vector<int> countBits(int num) {

		vector<int> res(num + 1);
		res[0] = 0;
		for (int i = 1; i < num + 1; i++) {
			//res[i] = res[i / 2] + i % 2;
			res[i] = res[i >> 1] + (i & 1);
		}
		return res;
	}
};

int main()
{
	Solution sln;
	vector<int> ans = sln.countBits(5);
	for (const auto & i : ans)
		cout << i << " ";
	cout << endl;
	std::cout << "Hello World!\n";
}
