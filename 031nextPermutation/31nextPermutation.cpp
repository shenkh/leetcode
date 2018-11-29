// 31nextPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


/*https://leetcode.com/problems/next-permutation/
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 0)
			return;

		auto pos = nums.end() - 1;
		
		//反向查找数列降序的位置
		while (pos != nums.begin() && *(pos) <= *(pos-1))
		{
			pos--;
		}
		//如果整个数列已经是降序的，则下一个字典排序为反转
		if (pos == nums.begin())
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		//确定降序值所在的位置
		auto left = pos - 1;
		
		//查找比降序值大的值(最小的那个,可能有很多个值比降序值大)
		pos = nums.end()-1;
		while (*left >= *pos)
		{
			pos--;
		}
		
		//将降序值与pos交换
		swap(*left, *pos);
		//反向后半段数据
		reverse(left+1, nums.end());
		return;
	}
};

#if 0
class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: A list of integers
	 */
	vector<int> nextPermutation(vector<int> &nums) {
		// write your code here
		int i = nums.size() - 2;
		while (i >= 0 && nums[i + 1] <= nums[i]) --i;
		if (i >= 0) {
			int j = nums.size() - 1;
			while (nums[j] <= nums[i]) --j;
			int tmp = nums[j];
			nums[j] = nums[i];
			nums[i] = tmp;
		}
		reverse(nums.begin() + i + 1, nums.end());
		return nums;
	}
};
#endif // 0

int main()
{
#if 0
	//原始的std中有next_permutation这个函数。
	/*next_permutation(num,num+n)函数是对数组num中的前n个元素进行全排列，同时并改变num数组的值。
另外，需要强调的是，next_permutation()在使用前需要对欲排列数组按升序排序，否则只能找出该序列之后的全排列数。*/
	vector<int> test{ 1,2,3 };
	bool result = next_permutation(test.begin(), test.end());
	for (auto const & i : test)
		cout << i;

#endif // 0

	Solution sln;
	vector<int> testcase{ 1,3,2 };
	sln.nextPermutation(testcase);
	for (auto const & i : testcase)
		cout << i << endl;
	std::cout << "Hello World!\n"; 
}
