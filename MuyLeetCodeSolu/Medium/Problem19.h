#pragma once

/*
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Problem19
{
public:
	static ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (nullptr == head->next)
		{
			ListNode* tempNode = head;
			head = nullptr;
			delete tempNode;
			return head;
		}

		ListNode* tempNodeA = nullptr;
		ListNode* tempNodeB = nullptr;
		ListNode* fakeHead = new ListNode(-1); // a fake head
		fakeHead->next = head;

		int tempStep = n;
		tempNodeB = tempNodeA = fakeHead;

		// find node (tempNodeB->next)
		while (nullptr != tempNodeA->next)
		{
			if (0 != tempStep)
			{
				tempNodeA = tempNodeA->next;
				tempStep--;
			}
			else
			{
				tempNodeA = tempNodeA->next;
				tempNodeB = tempNodeB->next;
			}
		}

		// remove node
		tempNodeA = tempNodeB->next;
		if (nullptr == tempNodeA->next)
		{
			tempNodeB->next = nullptr;
			delete tempNodeA;
		}
		else if (tempNodeA == head)
		{
			if (nullptr != head->next)
			{
				head = head->next;
				tempNodeA->next = nullptr;
				delete tempNodeA;
			}
			else
			{
				head = nullptr;
				delete head;
			}
		}
		else
		{
			tempNodeB->next = tempNodeA->next;
			tempNodeA->next = nullptr;
			delete tempNodeA;
		}

		fakeHead->next = nullptr;
		delete fakeHead;
		return head;
	}
};