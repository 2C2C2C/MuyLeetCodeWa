#pragma once

/*
160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/*
* Go through 2 list, calculate gap count and find the longer list.
* Start 2nd go through from heads, longer list move gaps first.
* Then move 2 list at same speed, do check(if equal) every steps.
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem160
{
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		// some edge cases
		if (nullptr == headA || nullptr == headB)
		{
			return nullptr;
		}
		else if (headA == headB)
		{
			return headA;
		}

		size_t gap = 0;
		ListNode* tempA = headA;
		ListNode* tempB = headB;
		bool aIsLonger = false, bIsLonger = false;
		do
		{
			if (aIsLonger || bIsLonger)
			{
				++gap;
				if (aIsLonger)
				{
					tempA = tempA->next;
					if (nullptr == tempA)
					{
						break;
					}
				}
				else if (bIsLonger)
				{
					tempB = tempB->next;
					if (nullptr == tempB)
					{
						break;
					}
				}
				continue;
			}

			// has not find longer list yet
			if (nullptr != tempA)
			{
				tempA = tempA->next;
			}

			if (nullptr != tempB)
			{
				tempB = tempB->next;
			}

			// check if we find the longer list
			aIsLonger = nullptr == tempB;
			bIsLonger = nullptr == tempA;
			if (aIsLonger && bIsLonger) // edge case, both reach the end
			{
				break;
			}
		} while (true);

		ListNode* longList = aIsLonger ? headA : headB;
		ListNode* shortList = aIsLonger ? headB : headA;

		while (0 < gap--)
		{
			longList = longList->next;
		}
		if (longList == shortList)
		{
			return shortList;
		}

		// find interest node
		while (nullptr != longList->next)
		{
			longList = longList->next;
			shortList = shortList->next;
			if (longList == shortList)
			{
				return shortList;
			}
		}
		return nullptr;
	}
};