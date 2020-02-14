// MuyLeetCodeSolu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <unordered_set>


//////// temp

int countPrimes(int n)
{
	int result = 2;
	switch (n)
	{
	case 0:
	case 1:
		return 0;
		break;
	case 2:
		return 1;
		break;
	default:
		break;
	}

	for (unsigned int i = 3; i < n; i = i + 2)
	{
		//if(i%3!=0)
	}
}



//////// temp


int main()
{
	std::cout << "Hello World!\n";

	std::cout << "End\n";
	return 0;
}
