// MuyLeetCodeSolu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//#include "Medium/Problem33 Search in Rotated Sorted Array.h"
//#include "Medium/Problem36 Valid Sudoku.h"
#include "Medium/Problem200 Number of Islands.h"
//////// temp


int main()
{
	std::cout << "Hello World!\n";
	//string result = Problem67::addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101");
	//string result = Problem67::addBinary("11", "1");
	//string result = Problem67::addBinary("1010", "1011");

	/*	
	["1", "1", "1", "1", "0"],
	["1", "1", "0", "1", "0"], 
	["1", "1", "0", "0", "0"], 
	["0", "0", "0", "0", "0"]*/

	std::vector<std::vector<char>> board = std::vector<std::vector<char>>();
	std::vector<char> temp = std::vector<char>();
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	board.push_back(temp);

	temp = std::vector<char>();
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('1');
	temp.push_back('0');
	board.push_back(temp);

	temp = std::vector<char>();
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	board.push_back(temp);

	temp = std::vector<char>();
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	board.push_back(temp);

	//tempArray.push_back(2);

	//std::cout << Problem33::search(tempArray, 5);

	Problem200::numIslands(board);

	//std::cout << "End\n";
	std::cout << "End\n";
	return 0;
}
