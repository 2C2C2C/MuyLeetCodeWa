﻿// MuyLeetCodeSolu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <string>
#include <vector>

// test
#include"ToxicToolA.h"

#include "Medium/Problem5.h"
#include "Medium/Problem22.h"
#include "Medium/Problem48.h"

//////// temp


int main()
{
	std::cout << "Hello World!\n";

	//std::vector<int> temp01;
	//temp01.push_back(0);
	//temp01.push_back(1);
	//temp01.push_back(2);

	//ListNode* nodePtr = nullptr;
	//ListNode tempNode = ToxicToolA<int>::GetLinkListFromArray(temp01);
	//nodePtr = &tempNode;

	//ToxicToolA<int>::ShowLinkList(*nodePtr);

	//std::string result = Problem5::longestPalindrome("babad");
	//std::cout << result << std::endl;

	//std::string resultWa1 = Problem22::GetAStr(3, true);
	//std::string resultWa2 = Problem22::GetAStr(3, false);

	int arrwa[] = { 1,2,3 };
	std::vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);

	std::vector<std::vector<int>> resWa;
	resWa.push_back(temp);
	resWa.push_back(temp);
	resWa.push_back(temp);
	resWa.push_back(temp);
	Problem48::rotate(resWa);

	std::cout << "End\n";
	return 0;
}
