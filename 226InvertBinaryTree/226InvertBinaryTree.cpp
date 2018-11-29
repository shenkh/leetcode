// 226InvertBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/invert-binary-tree
Invert a binary tree.

Example:

Input:

	 4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

	 4
   /   \
  7     2
 / \   / \
9   6 3   1*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> que;
		if (root == nullptr)
			return root;
		que.push(root);

		//≤„–Ú±È¿˙
		while (!que.empty())
		{
			int levellen = que.size();
			for (size_t i = 0; i < levellen; i++)
			{
				TreeNode* tmp = que.front();
				if (tmp->left != nullptr)
					que.push(tmp->left);
				if (tmp->right != nullptr)
					que.push(tmp->right);
				swap(tmp->left, tmp->right);
				std::cout << tmp->val << endl;
				que.pop();
			}
		}
		return root;
	}
};
#endif // 0


class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
		{
			return nullptr;
		}

		TreeNode * left = invertTree(root->left);
		TreeNode * right = invertTree(root->right);
		root->left = right;
		root->right = left;

		return root;
	}
};

int main()
{
	int *p = new int(3);
	int *p2 = new int(5);
	cout << *p << endl;
	cout << *p2 << endl;
	swap(p, p2);
	cout << *p << endl;
	cout << *p2 << endl;
	delete p, p2;
	std::cout << "2018-12-18.Hello World!\n";
}
