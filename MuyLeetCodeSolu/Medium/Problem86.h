#pragma once

/*
86. Partition List
https://leetcode.com/problems/partition-list/description/
*/

/*
* Prepare 2 sub linked list(left and right part).
* Travese source linked list.
* Check node value, 'value < x' case, put node into left part tail, else put into right part tail(x value node should be into right part).
* connect left part and right part as result.
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Problem86
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		if (nullptr == head)
		{
			return head;
		}

		ListNode* leftPart = new ListNode(-1);
		ListNode* rightPart = new ListNode(-1);

		ListNode* leftPartTail = leftPart;
		ListNode* rightPartTail = rightPart;
		ListNode* temp = head;
		do
		{
			ListNode* nodeCache = temp;
			temp = nodeCache->next;
			if (nodeCache->val < x) // this node should be left part
			{
				leftPartTail->next = nodeCache;
				leftPartTail = leftPartTail->next;
			}
			else // this node should be right part
			{
				rightPartTail->next = nodeCache;
				rightPartTail = rightPartTail->next;
			}
			nodeCache->next = nullptr;
		} while (nullptr != temp);

		if (-1 == leftPartTail->val) // left part is empty
		{
			return rightPart->next;
		}
		if (-1 == rightPartTail->val) // right part is empty
		{
			return leftPart->next;
		}

		leftPartTail->next = rightPart->next;
		return leftPart->next;
	}
};