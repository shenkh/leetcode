// 215KthLargestElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/kth-largest-element-in-an-array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order,
not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.*/

#if 0
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};
#endif // 0

//https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-PartitionMax-Heappriority_queuemultiset

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0;
		int r = nums.size() - 1;
		int p;
		while (true)
		{
			p = partition(nums, left, r);

			if (p == k - 1)
				return nums[p];
			else if (p < k - 1)
				left = p + 1;
			else if (p > k - 1)
				r = p - 1;
		}
	}
private:
	int partition(vector<int>& nums, int left, int r) {
		// 设置 left 所在位置为pivot
		int pivot = nums[left];
		int l = left + 1;
		while (l <= r)
		{
			if (nums[l] < pivot && nums[r] > pivot)
				swap(nums[l++], nums[r--]);
			if (nums[l] >= pivot)
				l++;
			if (nums[r] <= pivot)
				r--;
		}
		swap(nums[left], nums[r]);
		return r;
	}
};

int main()
{
	Solution sln;
	vector<int> testcase{ 3,3,3,3,3,3 };
	cout << sln.findKthLargest(testcase, 1) << endl;
	std::cout << "Hello World!\n";
}
