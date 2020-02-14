#pragma once

/*
237. Delete Node in a Linked List
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem237
{
public:
	static void deleteNode(ListNode* node)
	{
		ListNode* tempNode = node;
		ListNode* tail = nullptr;

		while (nullptr != tempNode->next)
		{
			tempNode->val = tempNode->next->val;
			tail = tempNode;
			tempNode = tempNode->next;
		}
		if (nullptr != tail)
			tail->next = nullptr;

		delete tempNode;
	}
};