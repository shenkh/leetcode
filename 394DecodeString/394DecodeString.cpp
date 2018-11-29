// 394DecodeString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;

/*https://leetcode.com/problems/decode-string/
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid;
No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".*/

class Solution {
public:
	string decodeString(string s) {
		int start = 0;
		return helper(s, start);
	}

private:
	//https://leetcode.com/problems/decode-string/discuss/87544/Clean-C%2B%2B-Recursive-Solution-with-Explanation
	/*	1.Every time we meet a '[', we treat it as a subproblem so call our recursive function to get the content in that '[' and ']'.
			After that, repeat that content for 'num' times.
		2.Every time we meet a ']', we know a subproblem finished and just return the 'word' we got in this subproblem.
		3.Please notice that the 'pos' is passed by reference, use it to record the position of the original string we are looking at.*/

	string helper(const string &s, int& i) {
		string ans;
		int num = 0;

		for (; i < s.length(); i++)
		{
			if (s[i] == '[') {
				string subletter = helper(s, ++i);
				//注意，这里必须更新num的值。否则例如'3[a]2[bc]'在算[bc]的次数时会变成32次。
				for (; num > 0; num--)
					ans += subletter;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
			}
			else if (s[i] == ']') {
				return ans;
			}
			else {
				ans.push_back(s[i]);
			}
		}
		return ans;
	}
};

int main()
{
	Solution sln;
	string testcase("2[abc]3[cd]ef");
	cout << sln.decodeString(testcase) << endl;
	std::cout << "Hello World!\n";
}
