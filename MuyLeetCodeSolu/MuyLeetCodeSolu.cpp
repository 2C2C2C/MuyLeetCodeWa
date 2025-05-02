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

#include "Medium/Problem91.h"

int main()
{
	std::cout << "Hello World!\n";
	// [1,5,0,4,1,3]

	//std::string source = "applepenapple";
	//std::vector<std::string> wordDict;
	//wordDict.push_back("apple");
	//wordDict.push_back("pen");

	//std::cout << "End\n";
	//std::string source = "1123";
	std::string source = "12";
	Problem91 p;
	int result = p.numDecodings(source);

	std::cout << result << std::endl;
	std::cout << "End\n";
	return 0;
}
