// 234PalindromeLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/palindrome-linked-list
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


#if 0
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr)
			return true;

		//将链表反转
		ListNode* preNode = nullptr;
		ListNode* current = head;
		ListNode* next = nullptr;

		vector<int> orderVal;

		while (current != nullptr)
		{
			orderVal.push_back(current->val);

			next = current->next;
			current->next = preNode;
			preNode = current;
			current = next;
		}

		//比较反转后的链表和原始链表的每个结点的值
		int i = 0;
		while (preNode != nullptr)
		{
			if (orderVal[i++] != preNode->val)
				return false;
			preNode = preNode->next;
		}
		return true;
	}
};

#endif // 0

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr)
			return true;

		ListNode *slow = head;
		ListNode *fast = head;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		//结点的个数为奇数
		if (fast != nullptr)
			slow = slow->next;

		ListNode * tail = reverseList(slow);

		while (tail != nullptr)
		{
			if (tail->val != head->val)
				return false;
			head = head->next;
			tail = tail->next;
		}
		return true;
	}

private:
	ListNode * reverseList(ListNode* head) {
		if (head == nullptr)
			return head;

		//将链表反转
		ListNode* preNode = nullptr;
		ListNode* current = head;
		ListNode* next = nullptr;

		vector<int> orderVal;

		while (current != nullptr)
		{
			orderVal.push_back(current->val);

			next = current->next;
			current->next = preNode;
			preNode = current;
			current = next;
		}
		return preNode;
	}
};

int main()
{
	std::cout << "2018-12-19.Hello World!\n";
}
