// LeetCode4MedianofTwoSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/median-of-two-sorted-arrays/
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5*/


class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//利用归并排序中的merge的思路

		int length = nums1.size() + nums2.size();  //数据的总个数
		vector<int> TR(length);  //存放归并后的结果

		int first = 0; //该变量对应与nums1中的位置
		int sec = 0;  //该变量对应与nums2中的位置
		int k = 0;		  //该变量对应与归并后结果的位置

		for (; first < nums1.size() && sec < nums2.size(); k++)
		{
			if (nums1[first] < nums2[sec])
				TR[k] = nums1[first++];
			else
				TR[k] = nums2[sec++];
		}

		//处理剩余的孤立数据
		while (first < nums1.size())
			TR[k++] = nums1[first++];   //将剩余的nums1复制到TR

		while (sec < nums2.size())
			TR[k++] = nums2[sec++];   //将剩余的nums2复制到TR

		double median;
		if (length % 2 == 0)
			median = (TR[length / 2] + TR[length / 2 - 1]) / 2.0;
		else
			median = TR[length / 2];
		return median;
	}
};

int main()
{
	Solution sort;
	vector<int> nums1{ 1,3 };
	vector<int> nums2{ 2,4 };
	double result = sort.findMedianSortedArrays(nums1, nums2);
	std::cout << result;
	std::cout << "Hello World!\n";
}
