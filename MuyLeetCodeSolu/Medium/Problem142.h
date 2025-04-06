#pragma once

/*
142. Linked List Cycle II
https://leetcode.com/problems/linked-list-cycle-ii/description/
*/

/*
* Use fast slow pointer, detect if there is cycle first.
* If there is cycle, set fast point to head.
* Fast and slow both move 1 node at once, when they meet, dat is cycle's head.
* When the 1st meet, fast move 2x, slow move x. Cycle length is c. Fast/slow pointer both move a extra distance in cycle from cycle's head, we call this distnace m, and we set cycle's head to linkedlist head distance as n.
* x = m + n; 2x = m + c + n; c = m + n;
* Since fast/slow alrady move n in the cycle, they just need to move m to get to the cycle's head(and also move m from head will reach cycle's head).
* So move fast pointer to head, and let fast & slow move 1 step at once.
* After m steps they will meet and dat is cycle's head.
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Problem142
{
public:
	ListNode* detectCycle(ListNode* head)
	{
		// handle some edge cases
		if (nullptr == head || nullptr == head->next)
		{
			return nullptr;
		}
		if (head->next == head)
		{
			return head;
		}

		ListNode* slowPtr = head;
		ListNode* fastPtr = head;

		do
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next;
			if (nullptr == fastPtr) // fast pointer goes to end
			{
				return nullptr;
			}
			fastPtr = fastPtr->next;

			if (slowPtr == fastPtr) // circle detected
			{
				fastPtr = head;
				if (fastPtr == slowPtr) // edge case, cycle start from head(slow move x, fast move 2x, cycle length is x).
				{
					return fastPtr;
				}
				do
				{
					fastPtr = fastPtr->next;
					slowPtr = slowPtr->next;
				} while (slowPtr != fastPtr);
				return fastPtr;
			}

		} while (nullptr != fastPtr);

		// fast pointer goes to end
		return nullptr;
	}
};