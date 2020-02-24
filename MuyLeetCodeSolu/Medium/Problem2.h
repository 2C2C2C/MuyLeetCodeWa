#pragma once

/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/
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
		int addWa = 0;
		bool flag = true;
		ListNode* fkerWa = new ListNode(0);
		ListNode* rootWa = fkerWa;

		while (flag)
		{
			fkerWa->val += addWa;
			if (l1)
				fkerWa->val += l1->val;
			if (l2)
				fkerWa->val += l2->val;

			if (fkerWa->val >= 10)
			{
				fkerWa->val -= 10;
				addWa = 1;
			}
			else
				addWa = 0;

			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;

			if (addWa == 0 && l1 == NULL && l2 == NULL)
			{
				flag = false;
				fkerWa->next = NULL;
				break;
			}
			else
			{
				fkerWa->next = new ListNode(0);
				fkerWa = fkerWa->next;
			}
		}

		return rootWa;
	}
};