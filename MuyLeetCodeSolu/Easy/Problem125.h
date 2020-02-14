#pragma once

/*
125. Valid Palindrome
https://leetcode.com/problems/valid-palindrome/
*/

#include <iostream>
#include <vector>

class Problem125
{
public:
	//
	static bool isPalindrome1(std::string str)
	{
		if (0 == str.length()) return true;
		std::vector<char> tempCharArr = GetPureAlpha(str);

		int head = 0;
		bool result = true;

		while (head < (tempCharArr.size() / 2))
		{
			result = result && (tempCharArr[head] == tempCharArr[tempCharArr.size() - head - 1]);
			head++;
			if (!result)
				return result;
		}

		return result;
	}

	static std::vector<char> GetPureAlpha(const std::string inStr)
	{
		char tempChar = '0';
		unsigned int i = -1;
		std::vector<char> *resultPtr = new std::vector<char>();
		while (++i < inStr.length())
		{
			tempChar = inStr[i];
			if (tempChar < 'a' || tempChar > 'z')
			{
				if ('A' <= tempChar && tempChar <= 'Z')
					tempChar += 'z' - 'Z'; // up to low case
				else if (tempChar < '0' || tempChar > '9')
					continue;
			}
			resultPtr->push_back(tempChar);
		}

		return *resultPtr;
	}

	//////////////////////

	static bool isPalindrome2(std::string str)
	{
		if (0 == str.length()) return true;

		std::string tempStr = str;
		int head = 0, back = str.length() - 1;
		bool result = true;

		while (head < back) // if equal or greater...
		{
			while (tempStr[head] < 'a' || tempStr[head] > 'z')
			{
				if (head >= tempStr.length() && back == tempStr.length() - 1)
					return true;

				if ('A' <= tempStr[head] && tempStr[head] <= 'Z')
					tempStr[head] += 'z' - 'Z'; // up to low case
				else if (tempStr[head] < '0' || tempStr[head] > '9')
					head++;
				else
					break;
			}

			// if "aa ,ssaa" , "   a"
			while (tempStr[back] < 'a' || tempStr[back] > 'z')
			{
				if ('A' <= tempStr[back] && tempStr[back] <= 'Z')
					tempStr[back] += 'z' - 'Z'; // up to low case
				else if (tempStr[back] < '0' || tempStr[back] > '9')
					back--;
				else
					break;
			}

			result = result && (tempStr[head] == tempStr[back]);
			if (!result)
				return result;
			head++; back--;
		}

		return result;
	}
};