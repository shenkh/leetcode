// 647PalindromicSubstrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/palindromic-substrings/
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.*/

class Solution {
public:
	int countSubstrings(string s) {
		if (s.length() == 0)
			return 0;

		vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

		int count = 0;
		for (int i = 0; i < s.length(); i++) {

			dp[i][i] = true;
			count++;
			if (i + 1 < s.length() && s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				//cout << i<<"," << i+1 << endl;
				count++;
			}
		}

		//截取substrlen长度的字符串,判断两侧的字符是否相等
		for (int substrlen = 1; substrlen <= s.length(); substrlen++) {
			for (int i = 1; i < s.length() - substrlen; i++) {
				int j = i + substrlen - 1;
				if (dp[i][j] && s[i - 1] == s[j + 1]) {
					dp[i - 1][j + 1] = true;
					//cout << i-1 <<"," << j+1 << endl;
					count++;
				}
			}
		}
		return count;
	}
};

class Solution2 {
public:
	int countSubstrings(string s) {
		for (size_t i = 0; i < s.size(); i++) {
			//分别考虑回文中心为奇数和偶数的情况
			expand(s, i, i);
			expand(s, i, i + 1);
		}
		return count;
	}

private:
	int count = 0;

	void expand(const string & s, int start, int end) {
		while (start >= 0 && end < s.length() && s[start] == s[end]) {
			start--;
			end++;
			count++;
		}
	}

};

int main(int argc, char const *argv[])
{
	Solution2 sln;
	cout << sln.countSubstrings("abccba") << endl;
	return 0;
}
