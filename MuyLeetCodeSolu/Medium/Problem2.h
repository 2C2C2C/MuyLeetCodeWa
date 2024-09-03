#pragma once

/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/
*/

/*
Create a new linked list for result.
Iterate 2 input linked list, add values if node is valid and cache the carry.
Keep doing it until 2 linked list are both finished.
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem2
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int carry = 0;
		bool doContinue = true;
		ListNode* resultNode = new ListNode(0);
		ListNode* resultRoot = resultNode;

		while (doContinue)
		{
			resultNode->val += carry;
			if (l1)
				resultNode->val += l1->val;
			if (l2)
				resultNode->val += l2->val;

			if (resultNode->val >= 10)
			{
				resultNode->val -= 10;
				carry = 1;
			}
			else
				carry = 0;

			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;

			if (carry == 0 && l1 == NULL && l2 == NULL)
			{
				doContinue = false;
				resultNode->next = NULL;
				break;
			}
			else
			{
				resultNode->next = new ListNode(0);
				resultNode = resultNode->next;
			}
		}

		return resultRoot;
	}
};