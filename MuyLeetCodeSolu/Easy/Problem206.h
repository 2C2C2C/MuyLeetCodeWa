#pragma once

/*
206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem206
{
public:

	static ListNode* reverseList(ListNode* head)
	{
		if (nullptr == head || nullptr == head->next) return head;

		ListNode* left = nullptr;
		ListNode* center = head;
		ListNode* right = nullptr;
		/* steps:
		* left (n-1) -> center (n) -> right (n+1)
		* left (n-1) <- center (n) -> right (n+1)
		* prev left (n-1) <- left (n) -> center (n+1) -> right (n+2)
		*/
		do
		{
			right = center->next;
			center->next = left;
			left = center;
			center = right;
		} while (nullptr != center->next);
		center->next = left;
		return center;
	}
};