// 617MergeTwoBinaryTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/*https://leetcode.com/problems/merge-two-binary-trees/
Given two binary trees and imagine that when you put one of them to cover the other,
some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap,
then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input:
	Tree 1                     Tree 2
		  1                         2
		 / \                       / \
		3   2                   1   3
	   /                           \   \
	  5                             4   7
Output:
Merged tree:
		 3
		/ \
	   4   5
	  / \   \
	 5   4   7


Note: The merging process must start from the root nodes of both trees.*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) {
			return nullptr;
		}

		int value = 0;
		if (t1 != nullptr)
			value += t1->val;
		if (t2 != nullptr)
			value += t2->val;

		//每进行递归一次，创建一个相应的结点保存结果
		TreeNode *head = new TreeNode(value);

		//对于某一棵二叉树已经遍历到结点为nullptr时，直接用nullptr作为其子结点
		head->left = mergeTrees(t1 == nullptr ? nullptr : t1->left, t2 == nullptr ? nullptr : t2->left);
		head->right = mergeTrees(t1 == nullptr ? nullptr : t1->right, t2 == nullptr ? nullptr : t2->right);

		return head;
	}
};

//https://leetcode.com/problems/merge-two-binary-trees/solution/
class Solution2 {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr)
			return t2;

		if (t2 == nullptr)
			return t1;

		t1->val += t2->val;

		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

		return t1;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
