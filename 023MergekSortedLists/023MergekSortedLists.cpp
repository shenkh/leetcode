// 023MergekSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/merge-k-sorted-lists/
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* meged_list = nullptr;
		if (lists.size() == 0)
			return nullptr;
		else if (lists.size() == 1)
			return lists[0];

		meged_list = mergeTwoLists(lists[0], lists[1]);
		for (size_t i = 2; i < lists.size(); i++)
			meged_list = mergeTwoLists(meged_list, lists[i]);
		return meged_list;
	}

private:
	ListNode* mergeTwoLists(ListNode* listnode, ListNode* listnode2) {
		ListNode* head_node = new ListNode(0);
		ListNode* res = head_node;

		while (listnode != nullptr && listnode2 != nullptr)
		{
			if (listnode->val < listnode2->val) {
				head_node->next = listnode;
				listnode = listnode->next;
			}
			else {
				head_node->next = listnode2;
				listnode2 = listnode2->next;
			}
			head_node = head_node->next;
		}

		if (listnode != nullptr)
			head_node->next = listnode;
		if (listnode2 != nullptr)
			head_node->next = listnode2;

		//删除创建的头结点,释放内存
		head_node = res;
		res = res->next;
		delete head_node;
		return res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
