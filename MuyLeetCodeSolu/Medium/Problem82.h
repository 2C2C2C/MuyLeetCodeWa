#pragma once

/*
82. Remove Duplicates from Sorted List II
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
*/

/*
* Use nested loops.
* Outer loop connect valid nodes(non dups).
* Inner loop need 2 pointer to indicate dup head and tail.
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Problem82
{
public:
	static ListNode* deleteDuplicates(ListNode* head)
	{
		if (nullptr == head || nullptr == head->next)
		{
			return head;
		}

		ListNode* resultHead = nullptr;
		ListNode* tempSafeNode = nullptr;
		ListNode* tempNextNode = nullptr;
		ListNode* tempPrevNode = head;
		do
		{
			tempNextNode = tempPrevNode->next;
			if (nullptr == tempNextNode || tempPrevNode->val != tempNextNode->val)
			{
				if (nullptr == resultHead)
				{
					resultHead = tempPrevNode;
				}
				tempSafeNode = tempPrevNode;
				tempPrevNode = tempNextNode;
				if (nullptr == tempPrevNode)
				{
					break;
				}
				continue;
			}

			// same value
			bool doLoop = true;
			do
			{
				tempPrevNode = tempNextNode;
				tempNextNode = tempPrevNode->next;
				doLoop = nullptr != tempNextNode &&
					tempPrevNode->val == tempNextNode->val;
			} while (doLoop);
			if (nullptr == tempSafeNode)
			{
				tempPrevNode = tempNextNode;
				continue;
			}
			tempSafeNode->next = tempNextNode;
			if (nullptr == tempNextNode)
			{
				break;
			}
			tempPrevNode = tempSafeNode->next;
		} while (nullptr != tempPrevNode);

		return resultHead;
	}

	//static void printToString(ListNode* head)
	//{
	//	if (nullptr == head)
	//	{
	//		std::cout << "NodeList: empty" << std::endl;
	//		return;
	//	}
	//	else if (nullptr == head->next)
	//	{
	//		std::cout << "NodeList: " << head->val << std::endl;
	//		return;
	//	}

	//	std::vector<int> tempList = std::vector<int>();
	//	ListNode* node = head;
	//	do
	//	{
	//		tempList.push_back(node->val);
	//		node = node->next;
	//	} while (nullptr != node);

	//	std::string output = "";
	//	for (unsigned i = 0, length = tempList.size(); i < length; i++)
	//	{
	//		output += (std::to_string(tempList[i]) + " ");
	//	}
	//	std::cout << "NodeList: " << output << std::endl;
	//}

};