#pragma once

/*
344. Reverse String
https://leetcode.com/problems/reverse-string/
*/

#include <iostream>
#include <vector>

class Problem344
{
public:
	static void reverseString(std::vector<char>& s)
	{
		for (unsigned int i = 0; i < s.size() / 2; i++)
			std::swap(s[i], s[s.size() - 1 - i]);
	}
};