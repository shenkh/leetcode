// 771JewelsAndStones.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<unordered_map>
using namespace std;

/*https://leetcode.com/problems/jewels-and-stones/
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:
Input: J = "z", S = "ZZ"
Output: 0

Note:
S and J will consist of letters and have length at most 50.
The characters in J are distinct.*/

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_map<char, int> char_num;
		int res = 0;
		for (const auto &c : J) {
			char_num[c] = 1;
		}

		//判断Stone中的每个元素是否在Jewels中
		for (const auto &c : S) {
			auto iter = char_num.find(c);
			if (iter != char_num.end())
				res++;
		}
		return res;
	}
};

class Solution2 {
public:
	int numJewelsInStones(string J, string S) {
		int res = 0;
		//只有大小写字母,对应的ASCII码A:65,a:97.
		int char_num[128] = { 0 };
		for (const auto &c : S) {
			char_num[c]++;
		}

		//对于Jewels中的每个元素,在Stone对应的char_num数组中查找
		for (const auto &c : J) {
			res += char_num[c];
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	Solution sln;
	cout << sln.numJewelsInStones("aA", "aAAbbbb") << endl;
	return 0;
}

