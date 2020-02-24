#pragma once

/*
13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/
*/

#include <iostream>

class Problem13
{
public:
	static int romanToInt(std::string inputStr)
	{
		// number mapping
		char romanAWa[] = { 'I','V','X','L','C','D','M' };
		int intAWa[] = { 1, 5, 10, 50, 100, 500, 1000 };

		int result = 0;
		bool startWa = false;
		bool findWa = false;
		for (int i = 0; i < sizeof(romanAWa); i++)// use to get roman char
		{
			for (int j = 0; j < inputStr.length(); j++)// use to get input char
			{
				if (inputStr[j] == romanAWa[i])// compare input char with roman char
				{
					if (j == inputStr.length() || i + 2 >= sizeof(romanAWa))
						result += intAWa[i]; // final digit of inputStr or last char of roman, must be add
					else if (inputStr[j + 1] == romanAWa[i + 1] || inputStr[j + 1] == romanAWa[i + 2])
						result -= intAWa[i]; // current roman number has bigger number right sied, this must be minus
					else
						result += intAWa[i];
				}
			}
		}
		return result;
	}
};