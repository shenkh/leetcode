// 102BinaryTreeLevelOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<queue>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/binary-tree-level-order-traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> que;

		if (root != NULL)
			que.push(root);
		while (!que.empty())
		{
			int levelnum = que.size(); //当前层的结点个数
			vector<int> p;

			for (size_t i = 0; i < levelnum; i++)
			{
				if (que.front()->left != NULL)
					que.push(que.front()->left);
				if (que.front()->right != NULL)
					que.push(que.front()->right);
				p.push_back(que.front()->val);
				que.pop();
			}
			ans.push_back(p);
		}
		return ans;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
