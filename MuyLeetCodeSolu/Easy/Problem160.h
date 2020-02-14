#pragma once

/*
160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem160
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int lenA = 0, lenB = 0, gap = 0;

		ListNode* longList = nullptr;
		ListNode* shortList = nullptr;
		ListNode* result = nullptr;

		longList = headA;
		while (nullptr != longList)
		{
			lenA++;
			longList = longList->next;
		}

		longList = headB;
		while (nullptr != longList)
		{
			lenB++;
			longList = longList->next;
		}

		// find and make balance
		if (0 == headA || 0 == headB)
			return result;
		else
		{
			gap = lenA - lenB;
			if (gap >= 0)
			{
				longList = headA;
				shortList = headB;
			}
			else
			{
				longList = headB;
				shortList = headA;
				gap = -gap;
			}
			while (gap-- > 0)
				longList = longList->next;
		}

		// find interest node
		while (nullptr != longList)
		{
			if (longList == shortList)
			{
				result = longList;
				break;
			}
			longList = longList->next;
			shortList = shortList->next;
		}

		return result;
	}
};