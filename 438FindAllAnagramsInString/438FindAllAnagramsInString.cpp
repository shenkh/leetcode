// 438FindAllAnagramsInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*https://leetcode.com/problems/find-all-anagrams-in-a-string/
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/

//https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {

		vector<int> res;
		unordered_map<char, int> target;
		for (const auto & c : p)
			target[c]++;

		//注意，这个取的是target.size()作为判断条件，而不是p.size()。因为p中有可能有重复的元素。
		int count = target.size();

		size_t begin = 0;
		size_t end = 0;
		while (end < s.size())
		{
			char tmp = s[end];
			if (target.find(tmp) != target.end())
			{
				target[tmp]--;
				if (target[tmp] == 0)
					count--;
			}
			end++;

			//此时begin到end之间已经包含了p所需的所有字符。
			while (count == 0)
			{
				char tmp = s[begin];
				if (target.find(tmp) != target.end())
				{
					target[tmp]++;
					if (target[tmp] > 0)
						count++;
				}

				if (end - begin == p.size())
					res.push_back(begin);

				begin++;
			}
		}
		return res;
	}
};

int main()
{
	Solution sln;
	vector<int> res = sln.findAnagrams("cbaebabacd", "abc");
	for (const auto &i : res)
		cout << i << " ";
	cout << endl;
	std::cout << "Hello World!\n";
}
