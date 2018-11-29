// 206ReverseLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/*https://leetcode.com/problems/reverse-linked-list
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL*/


struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		rlist = new ListNode(0);
		ListNode * headNode = rlist;
		helper(head);
		rlist->next = nullptr;
		return headNode->next;
	}
private:
	ListNode * rlist;

	void helper(ListNode*head) {
		if (head == nullptr)
			return;
		helper(head->next);
		rlist->next = head;
		rlist = rlist->next;
	}
};

int main()
{
    std::cout << "2018-12-15.Hello World!\n"; 
}
