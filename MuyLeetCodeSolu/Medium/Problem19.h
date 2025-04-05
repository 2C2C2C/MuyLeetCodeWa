#pragma once

/*
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/


/*
* Create a fake head, fake head's next node is input head.
* Use fast(to the end node) slow(to the node before to be removed) pointer(interval is n nodes) to Travese linked list.
* Delete the target node(the slow->next node).
* Return head.
* Be Careful with edge cases(to delete head; Linked list length is 1...etc);
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Problem19
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (nullptr == head->next)
		{
			ListNode* tempNode = head;
			head = nullptr;
			delete tempNode;
			return head;
		}

		ListNode* moveToEnd = nullptr; // use it to move to the end
		ListNode* nodeBeforeTarget = nullptr; // the node before the node to be removed
		ListNode* fakeHead = new ListNode(-1); // a fake head
		fakeHead->next = head;

		int tempStep = n;
		nodeBeforeTarget = moveToEnd = fakeHead;

		// using slow fast pointer to traverse linked list, fast pointer to the end and slow pointer to the node will be removed
		while (nullptr != moveToEnd->next) // move to last node 
		{
			if (0 != tempStep)
			{
				moveToEnd = moveToEnd->next;
				tempStep--;
			}
			else
			{
				moveToEnd = moveToEnd->next;
				nodeBeforeTarget = nodeBeforeTarget->next;
			}
		}

		// remove node
		ListNode* toRemove = nullptr;
		if (nodeBeforeTarget == fakeHead)
		{
			toRemove = head;
			head = head->next;
			delete toRemove;
			toRemove = nullptr;
			return head;
		}

		toRemove = nodeBeforeTarget->next;
		nodeBeforeTarget->next = nodeBeforeTarget->next->next;
		delete toRemove;
		return head;
	}
};