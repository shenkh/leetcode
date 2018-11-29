// 22generateParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>

/*https://leetcode.com/problems/generate-parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> ans;
		backtracking(ans, "", 0, 0, n);
		return ans;
	}

	void backtracking(vector<string> &ans, string result, int left, int right, int n)
	{
		if (result.size() == 2 * n)
		{
			ans.push_back(result);
			return;
		}

		//注意不要修改当前result的值，如result.append("(")则是错误的，会修改当前result的值，影响递归。
		if (left < n)
		{
#if 0
			//backtracking(ans, result + "(", left + 1, right, n);
#else
			result.push_back('(');
			backtracking(ans, result, left + 1, right, n);
			result.pop_back();
#endif 
	}

		if (left > right)
			backtracking(ans, result + ")", left, right + 1, n);
}
};

int main()
{
	Solution sln;
	vector<string> ans = sln.generateParenthesis(3);
	for (const auto & s : ans)
		std::cout << s << endl;
	std::cout << "Hello World!\n";
}

