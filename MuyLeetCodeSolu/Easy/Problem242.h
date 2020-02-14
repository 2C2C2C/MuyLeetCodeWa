#pragma once

/*
242. Valid Anagram
https://leetcode.com/problems/valid-anagram/
*/

#include <iostream>
#include <map>
#include <algorithm>

class Problem242 
{
public:
	static bool isAnagram(std::string s, std::string t)
	{
		if (s.length() != t.length()) return false;

		bool result = true;
		std::map<char, int> tempSet;
		unsigned int i = 0;

		std::sort(s.begin(), s.end());
		std::sort(t.begin(), t.end());

		for (i = 0; i < s.length(); i++)
		{
			if (s[i] != t[i])
			{
				result = false;
				break;
			}
		}

		return result;
	}
};