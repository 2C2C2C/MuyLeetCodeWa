#pragma once

/*
28. Implement strStr()
https://leetcode.com/problems/implement-strstr/
*/

#include <iostream>

class Problem28
{
public:
	static int strStr(std::string haystack, std::string needle)
	{
		// find needle from haystack
		if (needle.length() == 0)
			return 0;
		else if (haystack.length() == 0)
			return -1;

		bool get = false;
		for (int i = 0; i < haystack.length(); i++)
		{
			for (int j = 0; j < needle.length(); j++)
			{
				if (needle[j] != haystack[i + j])
					break;
				if (j == needle.length() - 1)
					get = true;
			}
			if (get)
				return i;
			else if (i >= haystack.length() - needle.length())
				break;
		}
		return -1;
	}
};