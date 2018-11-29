// 101SymmetricTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/symmetric-tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
	1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
	1
   / \
  2   2
   \   \
   3    3*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return helper(root, root);
	}

private:
	bool helper(TreeNode* left, TreeNode* right) {
		if (left == NULL && right == NULL)
			return true;
		if (left == NULL || right == NULL)
			return false;

		return (left->val == right->val) &&
			helper(left->left, right->right) &&
			helper(left->right, right->left);
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
