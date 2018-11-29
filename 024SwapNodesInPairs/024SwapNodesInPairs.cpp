// 024SwapNodesInPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/*https://leetcode.com/problems/swap-nodes-in-pairs/
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
Accepted*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11030/My-accepted-java-code.-used-recursion.
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		//每个pair中的第二个结点作为递归的返回值
		ListNode* ans = head->next;

		//更新每个pair中的第一个结点的指向，指向递归返回的结点
		head->next = swapPairs(head->next->next);

		//更新每个pair中的第二个结点的指向
		ans->next = head;
		return ans;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
