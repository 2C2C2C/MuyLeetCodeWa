#pragma once

#include <iostream>
#include <vector>

// they like to just use int, so.....
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
	static void ShowArr(const T arr[], const int arrLength);
	static std::vector<T> IntArrToVector(const T arr[], const int arrLength);

	static const ListNode& GetLinkListFromArray(const int arr[], const int arrLength);
	static const ListNode& GetLinkListFromArray(const std::vector<int>& tempVector);
	static void ShowLinkList(const ListNode& head);
};

