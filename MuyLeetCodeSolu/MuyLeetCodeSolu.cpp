﻿// MuyLeetCodeSolu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <string>
#include <vector>

// test
#include"ToxicToolA.h"

// temp test
//#include "Easy/Problem68.h"
//#include "Medium/Problem58.h"
//#include "Hard/Problem58.h"
// 
#include "Medium/Problem33.h"

//////// temp


int main()
{
	std::cout << "Hello World!\n";
	//string result = Problem67::addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101");
	//string result = Problem67::addBinary("11", "1");
	//string result = Problem67::addBinary("1010", "1011");

	std::vector<int> tempArray = std::vector<int>();
	tempArray.push_back(1);
	tempArray.push_back(3);
	tempArray.push_back(5);
	//tempArray.push_back(6);
	//tempArray.push_back(7);
	//tempArray.push_back(0);
	//tempArray.push_back(1);
	//tempArray.push_back(2);
	//tempArray.push_back(6);
	//tempArray.push_back(7);
	//tempArray.push_back(8);
	//tempArray.push_back(0);
	//tempArray.push_back(1);
	//tempArray.push_back(2);

	std::cout << Problem33::search(tempArray, 5);

	//std::cout << "End\n";
	std::cout << "End\n";
	return 0;
}
