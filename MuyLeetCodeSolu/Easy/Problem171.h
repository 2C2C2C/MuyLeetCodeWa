#pragma once

/*
171. Excel Sheet Column Number
https://leetcode.com/problems/excel-sheet-column-number/
*/

#include <iostream>

class Problem171
{
public:
	static int titleToNumber(std::string s)
	{
		int result = 0;
		for (unsigned int i = 0; i < s.length(); i++)
			result += std::pow(26, s.length() - i - 1) * (s[i] - 'A' + 1);

		return result;
	}
};