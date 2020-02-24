#pragma once

/*
21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem21
{
public:
	static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		// put l1 into l2
		if (!l2)
			return l1;
		ListNode* peekL1 = l1;
		ListNode* peekL2 = l2;
		ListNode* tmpL2 = l2;
		while (peekL1)
		{
			peekL2 = tmpL2 = l2;
			while (peekL2)
			{
				// l1 node <= l2 node, insert
				if (peekL1->val <= peekL2->val)
				{
					// create a new node, then insert l1 node here
					ListNode *nodeTmp1 = new ListNode(peekL1->val);
					if (peekL2 == l2)
					{
						nodeTmp1->next = l2;
						l2 = nodeTmp1;
						break;
					}
					else
					{
						tmpL2->next = nodeTmp1; // tempL2 is the previous node of peekL2
						nodeTmp1->next = peekL2;
						break;
					}
				}
				else
				{
					// if peekL2 out of index, add on the back of l2
					if (!peekL2->next)
					{
						// insert at the end
						ListNode* nodeTmp2 = new ListNode(peekL1->val);
						peekL2->next = nodeTmp2;
						break;
					}
					else
					{
						if (peekL2 != l2)
							tmpL2 = tmpL2->next;
						peekL2 = peekL2->next;
					}
				}
			}
			peekL1 = peekL1->next;
		}

		return l2;
	}
};