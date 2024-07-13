#pragma once

#include <iostream>
#include <vector>
#include <vector>

// normally they use int :D
struct ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

// this methods are used for debug while doing l337code
template<class T>
class ToxicToolA
{
public:
	static void ShowArr(const T* arr, const int arrLength)
	{
		if (arrLength < 1) return;
		std::cout << std::endl << "----start" << std::endl;
		for (unsigned int i = 0; i < arrLength; i++)
			std::cout << arr[i] << std::endl;
		std::cout << std::endl << "----end" << std::endl;
	}

	static std::vector<T> IntArrToVector(const T* arr, const int arrLength)
	{
		std::vector<T>* resultPtr = new std::vector<T>();
		if (arrLength < 1) return *resultPtr;

		for (unsigned int i = 0; i < arrLength; i++)
			resultPtr->push_back(arr[i]);

		return *resultPtr;
	}

	static ListNode& GetLinkListFromArray(const int* arr, const int arrLength)
	{
		if (0 == arrLength) return new ListNode(0);
		ListNode* head = nullptr;
		ListNode* tempPtr = nullptr;

		for (unsigned int i = 0; i < arrLength; i++)
		{
			if (0 == i)
			{
				tempPtr = new ListNode(arr[i]);
				head = tempPtr;
			}
			else
			{
				tempPtr->next = new ListNode(arr[i]);
				tempPtr = tempPtr->next;
			}
		}

		return *head;
	}

	static ListNode& GetLinkListFromArray(const std::vector<int>& tempVector)
	{
		if (0 == tempVector.size())
		{
			ListNode* tmpNode = new ListNode(0);
			return *tmpNode;
		}

		ListNode* head = nullptr;
		ListNode* tempPtr = nullptr;
		for (unsigned int i = 0; i < tempVector.size(); i++)
		{
			if (0 == i)
			{
				tempPtr = new ListNode(tempVector[i]);
				head = tempPtr;
			}
			else
			{
				tempPtr->next = new ListNode(tempVector[i]);
				tempPtr = tempPtr->next;
			}
		}

		return *head;
	}

	static void ShowLinkList(const ListNode& head)
	{
		std::cout << std::endl << "----start" << std::endl;
		const ListNode* tempPtr = nullptr;
		tempPtr = &head;
		while (nullptr != tempPtr)
		{
			std::cout << tempPtr->val << std::endl;
			tempPtr = tempPtr->next;
		}
		std::cout << "----end" << std::endl;
	}

	static void bubbleSortInt(std::vector<int>& arr)
	{
		int i = 0, j = 0, len = arr.size();
		if (len < 1) return;
		for (i = 0; i < len - 1; i++)
			for (j = 0; j < len - i - 1; j++) // the back has been set, so use n-i-1 as the limit
				if (arr[j] > arr[j + 1])
					std::swap(arr[j], arr[j + 1]);
	}

	static void bubbleSortInt(T* arr, const int len)
	{
		int i = 0, j = 0;
		if (len < 1) return;
		for (i = 0; i < len - 1; i++)
			for (j = 0; j < len - i - 1; j++) // the back has been set, so use n-i-1 as the limit
				if (arr[j] > arr[j + 1])
					std::swap(arr[j], arr[j + 1]);
	}

};

