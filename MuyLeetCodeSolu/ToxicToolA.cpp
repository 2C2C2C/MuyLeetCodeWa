#include "ToxicToolA.h"

template<class T>
void ToxicToolA<T>::ShowArr(const T arr[], const int arrLength)
{
	if (arrLength < 1) return;
	for (unsigned int i = 0; i < arrLength; i++)
		std::cout << arr[i] << std::endl;
}

template<class T>
std::vector<T> ToxicToolA<T>::IntArrToVector(const T arr[], const int arrLength)
{
	std::vector<T>* resultPtr = new std::vector<T>();
	if (arrLength < 1) return *resultPtr;

	for (unsigned int i = 0; i < arrLength; i++)
		resultPtr->push_back(arr[i]);

	return *resultPtr;
}

template<class T>
const ListNode& ToxicToolA<T>::GetLinkListFromArray(const int arr[], const int arrLength)
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

template<class T>
const ListNode & ToxicToolA<T>::GetLinkListFromArray(const std::vector<int>& tempVector)
{
	if (0 == tempVector.size()) return new ListNode(0);
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

template<class T>
void ToxicToolA<T>::ShowLinkList(const ListNode & head)
{
	ListNode* tempPtr = head;
	while (nullptr != tempPtr)
	{
		std::cout << tempPtr->val << std::endl;
		tempPtr = tempPtr->next;
	}
}

template<class T>
void ToxicToolA<T>::bubbleSortInt(std::vector<int> arr)
{
	int i = 0, j = 0, len = arr.size();
	if (len < 1) return;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - i - 1; j++) // the back has been set, so use n-i-1 as the limit
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

template<class T>
void ToxicToolA<T>::bubbleSortInt(const T arr[], const int len)
{
	int i = 0, j = 0;
	if (len < 1) return;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - i - 1; j++) // the back has been set, so use n-i-1 as the limit
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}
