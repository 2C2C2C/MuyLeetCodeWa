#pragma once

/*
141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/
*/

/*
* Use fast slow pointer.
* Fast pointer move 2 node, slow pointer move 1 node.
* If fast pointer move to end, no cycle.
* If fast pointer move the same position as slow poiner, has cycle.
* 
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Problem141
{
public:
	bool hasCycle(ListNode* head)
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