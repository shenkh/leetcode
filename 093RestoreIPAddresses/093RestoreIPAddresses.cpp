// 093RestoreIPAddresses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/restore-ip-addresses/
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]*/

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string single;
		backtracking(s, res, single, 0, 0);
		return res;
	}
private:
	void backtracking(string& s, vector<string>& res, string& single, int start, int dotnum) {
		if (dotnum == 4) {
			if (start == s.size()) {
				single.pop_back(); //移除最后一个多余的'.'
				res.push_back(single);
			}
			return;
		}

		for (int i = start; i < s.size(); ++i) {
			int length = i - start + 1;
			string sub = s.substr(start, length);
			if ((s[start] == '0' && length > 1) || length > 3 || stoi(sub) > 255)
				break;

			string ori_status(single);
			single += sub;
			single.push_back('.');
			backtracking(s, res, single, i + 1, dotnum + 1);
			single = ori_status;
		}
	}
};

int main()
{
	Solution sln;
	string testcase("25525511135");
	vector<string> res = sln.restoreIpAddresses(testcase);
	for (auto s : res)
		cout << s << endl;

	std::cout << "Hello World!\n";
}
