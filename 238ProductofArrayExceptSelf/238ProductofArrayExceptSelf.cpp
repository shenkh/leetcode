// 238ProductofArrayExceptSelf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/product-of-array-except-self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is
equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).*/

class Solution {
public:
	//https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space
	vector<int> productExceptSelf(vector<int>& nums) {
		//表示当前位置下左边所有元素的积
		vector<int> leftproduct(nums.size());
		leftproduct[0] = 1;
		for (size_t i = 1; i < nums.size(); i++)
		{
			leftproduct[i] = leftproduct[i - 1] * nums[i - 1];
		}

		//反向循环
		int right = 1;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			//当前位置左侧元素积 * 当前位置右侧元素的积
			leftproduct[i] *= right;
			right *= nums[i];
		}
		return leftproduct;
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 1,2,3,4 };
	vector<int> ans = sln.productExceptSelf(testcase);
	for (auto const & i : ans)
		cout << i << ",";
	cout << endl;
	std::cout << "2018-12-19.Hello World!\n";
}
