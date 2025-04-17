#pragma once

/*
83. Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Problem83
{
public:
	static ListNode* deleteDuplicates(ListNode* head)
	{
		if (nullptr == head || nullptr == head->next)
		{
			return head;
		}

		ListNode* tempNextNode = nullptr;
		ListNode* tempPrevNode = head;
		int prevNodeValue = head->val;
		do
		{
			tempNextNode = tempPrevNode->next;
			if (prevNodeValue == tempNextNode->val)
			{
				tempPrevNode->next = tempNextNode->next;
				// delete(tempNextNode); // unnecessary
				continue;
			}
			// differnt value
			prevNodeValue = tempNextNode->val;
			tempPrevNode = tempNextNode;
		} while (nullptr != tempPrevNode->next);
		return head;
	}

};