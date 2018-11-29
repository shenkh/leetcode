// 060PermutationSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/permutation-sequence/
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"

Given n and k, return the kth permutation sequence.

Note:
	Given n will be between 1 and 9 inclusive.
	Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<bool> used(n, false);
		string res;
		backtracking(n, k, used, res);
		return res;
	}

private:
	void backtracking(int n, int& k, vector<bool>& used, string& res) {
		if (res.size() == n) {
			--k;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (used[i]) continue;
			res.push_back(i + '1');
			used[i] = true;
			backtracking(n, k, used, res);
			//如果已经遍历到了第k个，结束所有的回溯
			if (k == 0) break;
			res.pop_back();
			used[i] = false;
		}
	}
};

/*https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)*/
class Solution1 {
public:
	string getPermutation(int n, int k) {
		//n个给定的元素
		vector<char> value(n);
		for (int i = 0; i < n; ++i) {
			value[i] = '1' + i;
		}

		//阶乘 factorial[] = {1, 1, 2, 6, 24, ... n!}
		vector<int> factorial(n + 1);
		factorial[0] = 1;
		for (int i = 1; i <= n; ++i) {
			factorial[i] = factorial[i - 1] * i;
		}

		string res;
		--k;  //从第0个开始

		//从value中的循环选择n个不重复的字符得到res
		//每次循环确定res[i]的值是多少。
		for (int i = 1; i <= n; ++i) {
			//确定k是落入数组value中第几个数开始的全排列
			int index = k / factorial[n - i];
			res.push_back(value[index]);
			//移除已经被选择过的
			value.erase(value.begin() + index);
			//因为我们已经确定了要求的值是在indx开头的全排列中，
			//因此要排除前面从0开头的全排列，从1开头的全排列...从index-1开头的全排列，更新k
			k -= index * factorial[n - i];
		}
		return res;
	}
};

int main()
{
	Solution sln;
	cout << sln.getPermutation(4, 9) << endl;
	std::cout << "Hello World!\n";
}
