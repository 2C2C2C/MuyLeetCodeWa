#pragma once

/*
876. Middle of the Linked List
https://leetcode.com/problems/linked-list-cycle-ii/description/
*/

/*
* Use fast slow pointer.
* Create a fake head, fake head' next is real head.
* Fast slow poiner both start from fake head. Fast move 2, slow move 1.
* Slow move 1 node first, then Fast move 1 node.
* Check if Fast's next is null.
* If so slow pointer current node is middle(cuz slow move x nodes, fast move 2x nodes; x will be the middle of 2x - 1).
* Fast move 1 more.
* if fast's next is null, slow's next is middle point(Right now slow move x nodes, fast move 2x nodes, it says take the 2nd middle point which is actually x + 1).
* Or repeat the movement.
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Problem876
{
public:
	ListNode* middleNode(ListNode* head)
	{
		if (nullptr == head)
		{
			return nullptr;
		}
		if (nullptr == head->next)
		{
			return head;
		}

		ListNode* fakeHead = new ListNode(-1);
		fakeHead->next = head;
		ListNode* slowPtr = fakeHead;
		ListNode* fastPtr = fakeHead;
		do
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next;
			if (nullptr == fastPtr->next)
			{
				return slowPtr;
			}
			fastPtr = fastPtr->next;
		} while (nullptr != fastPtr->next);

		return slowPtr->next;
	}
};