#pragma once

/*
206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem206
{
public:

	static ListNode* reverseList(ListNode* head)
	{
		if (nullptr == head || nullptr == head->next) return head;

		ListNode* tempA = nullptr;
		ListNode* tempB = nullptr;
		ListNode* tempC = nullptr;

		tempB = head;

		// tempA(next) <- tempB(current) -< tempC(prev)
		do
		{
			tempC = tempB->next;
			tempB->next = tempA;
			tempA = tempB;
			tempB = tempC;
		} while (nullptr != tempB->next);
		tempB->next = tempA;

		return tempB;
	}
};