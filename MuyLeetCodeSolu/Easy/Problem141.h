#pragma once

/*
141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/
*/

#include <iostrseam>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem141
{
public:

	static bool hasCycle(ListNode* head)
	{
		bool result = false;
		if (nullptr == head) return result;

		ListNode* slowPtr = head;
		ListNode* fastPtr = head;

		while (nullptr != fastPtr->next)
		{
			fastPtr = fastPtr->next;
			if (nullptr == fastPtr->next)
				return result;
			else
				fastPtr = fastPtr->next;

			if (fastPtr == slowPtr)
			{
				result = true;
				break;
			}
			else
				slowPtr = slowPtr->next;
		}

		return result;
	}
};