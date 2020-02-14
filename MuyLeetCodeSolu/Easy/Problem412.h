#pragma once

/*
412. Fizz Buzz
https://leetcode.com/problems/fizz-buzz/
*/

#include <iostream>
#include <vector>
#include <string>

class Problem412
{
	static std::vector<std::string> fizzBuzz(int n)
	{
		std::vector<std::string>* result = new std::vector<std::string>();
		std::string strFizz = "Fizz";
		std::string strBuzz = "Buzz";
		std::string* tempStrPtr = nullptr;

		for (unsigned int i = 1; i <= n; i++)
		{
			tempStrPtr = new std::string("");
			if (i % 3 == 0)
				tempStrPtr->append(strFizz);
			if (i % 5 == 0)
				tempStrPtr->append(strBuzz);
			if (tempStrPtr->length() == 0)
				tempStrPtr->append(std::to_string(i));

			result->push_back(*tempStrPtr);
		}

		return *result;
	}
};

