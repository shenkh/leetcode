// 94BinaryTreeInorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/binary-tree-inorder-traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
	\
	 2
	/
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?*/


/* Definition for a binary tree node. */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		helper(root, ans);
		return ans;
	}
private:
	void helper(TreeNode* root, vector<int>& ans) {
		if (root == NULL)
			return;

		helper(root->left, ans);
		ans.push_back(root->val);
		helper(root->right, ans);
	}
};
#else

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		vector<TreeNode*> stack;
		while (root != NULL || stack.size() != 0)
		{
			while (root != NULL)
			{
				stack.push_back(root);
				root = root->left;
			}
			root = stack.back();
			stack.pop_back();
			ans.push_back(root->val);
			root = root->right;
		}
		return ans;
	}
};
#endif // 0


int main()
{
	std::cout << "Hello World!\n";
}
