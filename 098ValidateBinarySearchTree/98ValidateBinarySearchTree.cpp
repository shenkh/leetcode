// 98ValidateBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stack>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/validate-binary-search-tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> StackNode;
		TreeNode * preNode = NULL;

		while (root != NULL || StackNode.size() != 0)
		{
			while (root != NULL) {
				StackNode.push(root);
				root = root->left;
			}
			root = StackNode.top();
			StackNode.pop();

			if (preNode != NULL && root->val <= preNode->val)
				return false;

			preNode = root;
			root = root->right;
		}
		return true;
	}
};
int main()
{
	std::cout << "Hello World!\n";
}
