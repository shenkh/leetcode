// 437PathSumIII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<unordered_map>
using namespace std;

/*https://leetcode.com/problems/path-sum-iii/
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf,
but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

	  10
	 /  \
	5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//https://leetcode.com/problems/path-sum-iii/discuss/91889/Simple-Java-DFS
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;
		int ans = 0;
		helper(root, ans, sum);
		return ans + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

private:
	void helper(TreeNode* root, int &ans, int remain) {
		if (root == nullptr)
			return;

		remain -= root->val;
		if (remain == 0)
			ans++;

		helper(root->left, ans, remain);
		helper(root->right, ans, remain);
	}
};

//https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method
class Solution2 {
public:
	int pathSum(TreeNode* root, int sum) {
		int res = 0;
		//key：前i个元素的和，value：对应和的个数
		unordered_map<int, int> sum_counts;
		int current_sum = 0;
		sum_counts[current_sum]++;
		preSum(root, sum_counts, current_sum, sum, res);
		return res;
	}

private:
	void preSum(TreeNode* root, unordered_map<int, int>& sum_counts, int& current_sum, int& target_sum, int& res) {
		if (root == nullptr)
			return;

		current_sum += root->val;
		auto iter = sum_counts.find(current_sum - target_sum);
		if (iter != sum_counts.end())
			res += iter->second;

		sum_counts[current_sum]++;

		preSum(root->left, sum_counts, current_sum, target_sum, res);
		preSum(root->right, sum_counts, current_sum, target_sum, res);

		sum_counts[current_sum]--;
		current_sum -= root->val;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
