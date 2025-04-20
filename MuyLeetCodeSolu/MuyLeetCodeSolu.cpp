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

#include "Easy/Problem104.h"

int main()
{
	std::cout << "Hello World!\n";

	TreeNode* node1 = new TreeNode(1);
	node1->left = new TreeNode(2);
	node1->right = new TreeNode(3);
	node1->left->right = new TreeNode(4);

	Problem104 p;
	p.maxDepth(node1);

	//std::cout << "End\n";
	std::cout << "End\n";
	return 0;
}
