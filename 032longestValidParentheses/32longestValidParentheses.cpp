// 32longestValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/longest-valid-parentheses/
Given a string containing just the characters '(' and ')',
find the length of the longest valid(well - formed) parentheses substring。

Example 1:

Input: "(()"
	Output : 2
	Explanation : The longest valid parentheses substring is "()"*/

class Solution {
public:
	int longestValidParentheses(string s) {
		int length = s.size();
		if (length == 0 || length == 1)
			return 0;
		//dp用来表示当前下标之前的字符中有效括弧的长度
		int * dp = new int[length];
		memset(dp, 0, sizeof(int)*length);

		//只有结尾是')'闭括号才需要更新dp数组。
		//此时共有两种情况，'()'和'))'.

		for (int i = 1; i < length; i++)  //注意i不要用size_t类型
		{
			//只判断字符为')'的情况
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					//如果前一个字符刚好为'(',则加上dp[i-2]的长度，注意边界的判断
					dp[i] = (i - 2) >= 0 ? dp[i - 2] + 2 : 2;
				}
				else if (s[i - 1] == ')' && s[i - dp[i - 1] - 1] == '(')
				{
					//如果前一个字符为')',则往前推算dp[i-dp[i-1]-1]的字符是否为'('
					dp[i] = (i - dp[i - 1] - 2) >= 0 ?
						dp[i - 1] + 2 + dp[i - dp[i - 1] - 2] : dp[i - 1] + 2;
				}
			}
		}
		int value = *std::max_element(dp, dp + length);
		delete[] dp;
		return value;
	}
};

int main()
{
	Solution sln;
	cout << sln.longestValidParentheses("(())") << endl;
	std::cout << "Hello World!\n";
}
