#pragma once

/*
5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
*/

#include <iostream>

class Problem5
{
public:
	static std::string longestPalindrome(std::string inputStr)
	{
		if (2 > inputStr.length())
			return inputStr;
		else if (inputStr.length() == 2)
		{
			if (inputStr[0] != inputStr[1])
				return inputStr.substr(0, 1);
			else
				return inputStr;
		}

		std::string result = "";
		int maxlen = 0, strLen = inputStr.length(), left = 0, right = 0;
		int i = 0, j = 0;

		// check 'abba'
		for (i = 0; i < strLen - 1; i++)
		{
			left = i;
			right = i + 1;
			j = 0;
			while (true)
			{
				if (inputStr[left - j] == inputStr[right + j])
				{
					j++;
					if (left - j < 0 || right + j == strLen)
					{
						j--;
						break;
					}
				}
				else
				{
					if (j > 0)
						j--;
					else
						j = -1;
					break;
				}
			}

			if (j >= 0 && maxlen < 2 * (j + 1)) // length is 2*(j+1)
			{
				// seems like we find a str
				result = inputStr.substr(left - j, 2 * (j + 1));
				maxlen = result.length();
			}
		}

		// check 'ab?ba'
		for (i = 1; i < strLen - 1; i++)
		{
			left = i - 1;
			right = i + 1;
			j = 0;
			while (true)
			{
				if (inputStr[left - j] == inputStr[right + j])
				{
					j++;
					if (left - j < 0 || right + j == strLen)
					{
						j--;
						break;
					}
				}
				else
				{
					if (j > 0)
						j--;
					else
						j = -1;
					break;
				}
			}

			if (j >= 0 && maxlen < 2 * (j + 1) + 1)
			{
				result = inputStr.substr(left - j, 2 * (j + 1) + 1);
				maxlen = result.length();
			}

		}

		if (0 == maxlen)
			return inputStr.substr(0, 1);
		else
			return result;
	}
};