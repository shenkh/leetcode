// 17LetterCombinations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;


/*https://leetcode.com/problems/letter-combinations-of-a-phone-number/
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
利用回溯法解决*/


class Solution {
public:
	vector<vector<char> > table{ {'0'},{'1'},{'a', 'b', 'c'},
	{'d', 'e', 'f'},{'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
	{'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'} };

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.size() > 0)
		{
			string local;
			backtracking(digits, res, local, 0);
		}
		return res;
	}
	//digit为输入的数字字符串，res表示返回的所有字符串的集合,
	//local表示的是可能的字符串(local的长度是从0开始变化的),index表示指向的数字字符串的位置
	void backtracking(string& digits, vector<string>& res, string& local, int index)
	{
		if (index == digits.size())
		{
			res.push_back(local);
			return;
		}
		else
		{
			//获取当前位置(index)的数字所能取的字母
			int num = digits[index] - '0';

			//字符串数字对应的字母表长度不一定，所以判断条件用的是table[index].size()
			for (size_t i = 0; i < table[num].size(); i++)
			{
				local.push_back(table[num][i]);
				//获取下一个位置(index+1)的数字所能取的字母
				backtracking(digits, res, local, index + 1);
				local.pop_back();
			}
		}
	}
};


int main()
{
	Solution sol;
	vector<string> res = sol.letterCombinations("7");
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << endl;;
	}
	std::cout << "Hello World!\n";
}
