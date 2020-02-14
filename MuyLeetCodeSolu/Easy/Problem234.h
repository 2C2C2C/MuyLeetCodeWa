#pragma once

/*
234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/
*/

#include <iostream>
#include <vector>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Problem234
{
public:

	static bool isPalindrome(ListNode* head)
	{
		if (nullptr == head || nullptr == head->next)
			return true;

		bool result = true;
		std::vector<int> tempVc;
		ListNode* tempNode = head;

		while (nullptr != tempNode)
		{
			tempVc.push_back(tempNode->val);
			tempNode = tempNode->next;
		}

		for (unsigned int i = 0; i < tempVc.size() / 2; i++)
		{
			if (tempVc[i] == tempVc[tempVc.size() - i - 1])
				continue;
			else
			{
				result = false;
				break;
			}
		}

		return result;
	}

};

