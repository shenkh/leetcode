// 169MajorityElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/majority-element
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2*/


#if 1
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> tables; //key为元素值,value为元素对应的个数
		for (size_t i = 0; i < nums.size(); i++) {
			tables[nums[i]]++;
		}

		//对tables按照值大小排序
		multimap<int, int> tables_r; //key为元素的个数,value为元素值
		for (auto iter = tables.begin(); iter != tables.end(); iter++) {
			tables_r.insert(pair<int, int>(iter->second, iter->first));
		}

		return tables_r.rbegin()->second;
	}
};

#else
//https://leetcode.com/problems/majority-element/solution/
class Solution {
public:
	int majorityElement(vector<int> & nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};
#endif // 0

int main()
{
	Solution sln;
	vector<int> testcase{ 2,2,1,1,1,2,2 };
	cout << sln.majorityElement(testcase) << endl;
	std::cout << "Hello World!\n";
}
