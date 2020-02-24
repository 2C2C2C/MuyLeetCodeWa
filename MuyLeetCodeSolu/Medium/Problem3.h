#pragma once

/*
 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <unordered_map>

class Problem3
{
public:
	static int lengthOfLongestSubstring(std::string _str)
	{
		if (_str == "")
			return 0;

		std::unordered_map<char, int> charAndPos; // check fast
		int currentSubStrLength = 0, lastSubStrLength = 0, strStartIndex = 0;;

		for (int i = 0; strStartIndex + currentSubStrLength < _str.length() && i < _str.length(); i++)
		{
			// check next chara repeat or not
			if (charAndPos.empty() || charAndPos.find(_str[i]) == charAndPos.end())
			{
				charAndPos.insert(std::pair<char, int>(_str[i], i));
				currentSubStrLength++;
			}
			else
			{
				// find repeat char, reset i(check pos) to the repeat char's previous pos
				i = charAndPos[_str[i]];
				charAndPos.clear();
				if (currentSubStrLength > lastSubStrLength)
					lastSubStrLength = currentSubStrLength;
				currentSubStrLength = 0;
			}
		}
		if (currentSubStrLength > lastSubStrLength)
			lastSubStrLength = currentSubStrLength;

		return lastSubStrLength;
	}
};