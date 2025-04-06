// MuyLeetCodeSolu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <string>
#include <vector>

//#include"ToxicToolA.h"
// temp
//#include "Easy/Problem.h"
//#include "Medium/Problem.h"
//#include "Hard/Problem.h"

#include "Medium/Problem142.h"

int main()
{
	std::cout << "Hello World!\n";

	std::vector<ListNode*> lists;
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
	a1->next = a2;
	a2->next = a3;
	a3->next = a1;

	Problem142 p;
	p.detectCycle(a1);

	//std::cout << "End\n";
	std::cout << "End\n";
	return 0;
}
