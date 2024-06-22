#pragma once

/*
58. Length of Last Word
https://leetcode.com/problems/length-of-last-word/
*/

#include <iostream>
using namespace std;

class Problem58
{
public:
	static int lengthOfLastWord(string s)
	{
		int strLength = s.length();
		if (strLength < 1)
		{
			return 0;
		}
		else if (strLength == 1)
		{
			return s[0] == ' ' ? 0 : 1;
		}

		bool hasStart = false;
		int result = 0;
		for (int i = strLength - 1; i >= 0; i--)
		{
			bool isCurrentEmptySpace = ' ' == s[i];
			if (hasStart)
			{
				if (isCurrentEmptySpace)
				{
					break;
				}
				result++;
			}
			else if (!isCurrentEmptySpace)
			{
				hasStart = true;
				result++;
			}
		}

		return result;
	}
};