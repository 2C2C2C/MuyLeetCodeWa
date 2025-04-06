#pragma once

/*
23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

/*
* Since there are k sorted list, we need a priority queue to get the smallest one.
* Put all head nodes into queue.
* Get smallest from queue, dequeue node, put into result.
* Check the node we dequeued, it belongs to some linkedlist.
* Let dat linkedlist insert next node into queue(if next node is valid).
* Keep dequeue smallest node until queue is empty and also traverse all linked list.
*/

#include<vector>
#include<queue>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Problem23
{
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists)
	{
		if (lists.empty())
		{
			return nullptr;
		}

		auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
		std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> nodeQueue(compare);
		ListNode* fakeHead = new ListNode(-1); // use a fake head to connect result, result will be fakeHead->next
		ListNode* tempResult = fakeHead;

		size_t linkedListCount = lists.size();
		std::vector<ListNode*> tempNodes;
		for (size_t i = 0; i < linkedListCount; i++)
		{
			tempNodes.push_back(lists[i]);
		}

		bool keepLoop;
		int prevPopLinkedlistIndex = -1;

		// fill first nodes
		for (size_t i = 0; i < linkedListCount; i++)
		{
			if (nullptr == tempNodes[i])
			{
				continue;
			}
			ListNode* nodeToPush = tempNodes[i];
			nodeQueue.push(nodeToPush);
		}

		do
		{
			if (-1 != prevPopLinkedlistIndex && nullptr != tempNodes[prevPopLinkedlistIndex])
			{
				ListNode* nodeToPush = tempNodes[prevPopLinkedlistIndex];
				nodeQueue.push(nodeToPush);
			}
			prevPopLinkedlistIndex = -1;

			if (nodeQueue.empty())
			{
				break;
			}

			ListNode* toPushIntoResult = nodeQueue.top();
			nodeQueue.pop();
			for (size_t i = 0; i < linkedListCount; i++)
			{
				if (toPushIntoResult == tempNodes[i])
				{
					prevPopLinkedlistIndex = i;
					tempNodes[i] = toPushIntoResult->next;
					break;
				}
			}
			toPushIntoResult->next = nullptr;
			tempResult->next = toPushIntoResult;
			tempResult = tempResult->next;

			if (nodeQueue.empty())
			{
				for (size_t i = 0, length = tempNodes.size(); i < length; i++)
				{
					if (nullptr == tempNodes[i])
					{
						continue;
					}
					keepLoop = false;
					break;
				}
				keepLoop = true;;
			}
			else
			{
				keepLoop = true;
			}
		} while (keepLoop);
		return fakeHead->next;
	}
};