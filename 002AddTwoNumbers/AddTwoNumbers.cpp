// AddTwoNumbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

/*https://leetcode.com/problems/add-two-numbers/
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.*/


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		int position_sum = 0;
		ListNode * res = new ListNode(0);
		ListNode * p = res;
		//position_sum!=0是为了防止两个数最高位数相同，有进位的情况，如500，501
		while (l1 != NULL | l2 != NULL | position_sum != 0)
		{
			if (l1 != NULL)
			{
				position_sum += l1->val;
				l1 = l1->next;
			}

			if (l2 != NULL)
			{
				position_sum += l2->val;
				l2 = l2->next;
			}
			//尾插法
			ListNode * node = new ListNode(position_sum % 10);
			p->next = node;
			p = node;
			position_sum /= 10;
		}
		return res->next;
	}
};

int main()
{
	return 0;
}
