// 104MaximumDepthofBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<queue>
using namespace std;

/*https://leetcode.com/problems/maximum-depth-of-binary-tree
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
return its depth = 3.*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int depth = 0;
		queue<TreeNode*> que;
		if (root != nullptr)
			que.push(root);
		while (!que.empty())
		{
			int length = que.size();
			for (size_t i = 0; i < length; i++)
			{
				if (que.front()->left != nullptr)
					que.push(que.front()->left);
				if (que.front()->right != nullptr)
					que.push(que.front()->right);
				que.pop();
			}
			depth++;
		}
		return depth;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
