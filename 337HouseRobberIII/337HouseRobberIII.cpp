// 337HouseRobberIII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/house-robber-iii/
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house.
After a tour, the smart thief realized that "all houses in this place forms a binary tree".
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
Input: [3,2,3,null,3,null,1]
	 3
	/ \
   2   3
	\   \
	 3   1
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
Input: [3,4,5,1,3,null,1]
	 3
	/ \
   4   5
  / \   \
 1   3   1
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
#if 0
class Solution {
public:
	int rob(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int val = 0;
		if (root->left != nullptr)
			val += rob(root->left->left) + rob(root->left->right);

		if (root->right != nullptr)
			val += rob(root->right->left) + rob(root->right->right);

		return max(rob(root->left) + rob(root->right), val + root->val);
	}
};
#endif

class Solution {
public:
	int rob(TreeNode* root) {
		int root_include, root_exclude;
		robSub(root, root_include, root_exclude);
		return max(root_include, root_exclude);
	}

private:
	void robSub(TreeNode *root, int &root_include, int &root_exclude) {
		if (root == nullptr)
		{
			root_include = 0;
			root_exclude = 0;
			return;
		}

		//left_include表示选择左结点能够获得的最大值
		//left_exclude表示不选择左结点能够获得的最大值
		int left_include, left_exclude;
		robSub(root->left, left_include, left_exclude);

		//right_include表示选择右结点能够获得的最大值
		//right_exclude表示不选择右结点能够获得的最大值
		int right_include, right_exclude;
		robSub(root->right, right_include, right_exclude);

		root_include = root->val + left_exclude + right_exclude;
		//注意root_exclude的转移函数。
		root_exclude = max(left_include, left_exclude) + max(right_include, right_exclude);
	}
};


int main()
{
	std::cout << "Hello World!\n";
}
