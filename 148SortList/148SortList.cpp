// 148SortList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/*https://leetcode.com/problems/sort-list
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode * pre = nullptr, *l1, *l2;
		l1 = head, l2 = head;
		//切分
		while (l2 != nullptr && l2->next != nullptr)
		{
			pre = l1;
			l1 = l1->next;
			l2 = l2->next->next;
		}

		pre->next = nullptr;

		//对各部分进行排序
		ListNode* r1 = sortList(head);
		ListNode* r2 = sortList(l1);

		return merge(r1, r2);
	}

private:
	//合并
	ListNode* merge(ListNode* l1, ListNode*l2) {
		ListNode * result = new ListNode(0);
		ListNode * ans = result;

		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val)
			{
				result->next = l1;
				l1 = l1->next;
			}
			else
			{
				result->next = l2;
				l2 = l2->next;
			}
			result = result->next;
		}

		if (l1 != nullptr)
			result->next = l1;
		if (l2 != nullptr)
			result->next = l2;

		return ans->next;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
