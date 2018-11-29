// 20ValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


/*https://leetcode.com/problems/valid-parentheses/
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.*/


class Solution {
public:
	map<char, int> table{ {'(' ,-1}, {')' , 1}, {'{' ,-2}, {'}' , 2}, {'[' ,-3}, {']' , 3} };
	bool isValid(string s) {
		vector<int> stack;


		map<char, int>::iterator p;
		for (size_t i = 0; i < s.size(); i++)
		{
			p = table.find(s[i]);
			//如果是非法字符，返回false
			if (p == table.end())
				return false;
			else
			{
				//如果当前栈中没有元素，则直接压栈
				if (stack.size() == 0)
					stack.push_back(p->second);
				else
				{
					//判断新压栈的数据能否和之前的匹配上，能匹配则将其出栈，否则继续压栈
					if (*(stack.end() - 1) + p->second == 0)
						stack.pop_back();
					else
						stack.push_back(p->second);
				}
			}
		}

		//如果所有的字符能匹配上，则栈应该是空的
		if (stack.size() == 0)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution sln;
	cout << sln.isValid("()") << endl;
	cout << sln.isValid("()[]{}") << endl;
	cout << sln.isValid("(]") << endl;
	cout << sln.isValid("([)]") << endl;
	cout << sln.isValid("{[]}") << endl;
    std::cout << "Hello World!\n"; 
}
