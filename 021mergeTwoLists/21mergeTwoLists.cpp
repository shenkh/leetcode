// 21mergeTwoLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/*https://leetcode.com/problems/merge-two-sorted-lists/
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode * mergeList = new ListNode(0);
		ListNode * ans = mergeList;

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				mergeList->next = l1;
				l1 = l1->next;
			}
			else
			{
				mergeList->next = l2;
				l2 = l2->next;
			}
			mergeList = mergeList->next;
		}

		if (l1 != NULL)
			mergeList->next = l1;
		if (l2 != NULL)
			mergeList->next = l2;

		return ans->next;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

