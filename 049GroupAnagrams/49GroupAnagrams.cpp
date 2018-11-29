// 49GroupAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/group-anagrams/
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		//key为排好序的字符串
		map<string, vector<string>> index_value;
		for (size_t i = 0; i < strs.size(); i++)
		{
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			index_value[tmp].push_back(strs[i]);
		}

		//将结果输出
		vector<vector<string>> ans;
		for (auto map_it = index_value.cbegin(); map_it != index_value.cend(); map_it++)
		{
			ans.push_back(map_it->second);
		}
		return ans;
	}
};

int main()
{
	Solution sln;
	vector<string> test_case{ "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string> > ans = sln.groupAnagrams(test_case);
	for (const auto & i : ans)
	{
		for (const auto & j : i)
			cout << j << ' ';
		cout << endl;
	}

	std::cout << "Hello World!\n";
}
