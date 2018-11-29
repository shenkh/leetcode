// 538ConvertBSTtoGreaterTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stack>
using namespace std;

/*https://leetcode.com/problems/convert-bst-to-greater-tree/
Given a Binary Search Tree (BST), convert it to a Greater Tree
such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
			  5
			/   \
		   2     13

Output: The root of a Greater Tree like this:
			 18
			/   \
		  20     13*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//reverse in-order traversal.
class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		int sum = 0;
		helper(root, sum);
		return root;
	}

private:
	void helper(TreeNode *root, int& sum) {
		if (root == nullptr)
			return;

		helper(root->right, sum);
		sum += root->val;
		root->val = sum;
		helper(root->left, sum);
	}
};

//iteration
class Solution2 {
public:
	TreeNode* convertBST(TreeNode* root) {
		int sum = 0;
		stack<TreeNode*> stack_node;
		TreeNode *res = root;
		while (root != nullptr || stack_node.size() != 0) {
			while (root != nullptr) {
				stack_node.push(root);
				root = root->right;
			}

			TreeNode *node = stack_node.top();
			stack_node.pop();
			sum += node->val;
			node->val = sum;

			root = node->left;
		}
		return res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
