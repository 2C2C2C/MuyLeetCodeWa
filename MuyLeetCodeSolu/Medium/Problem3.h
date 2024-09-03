#pragma once

/*
 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

/*
* Use a hashset for storing char from current checking longest string.
* (Go through the string)Check char from the string, if the set does not contains current char, add it.
* If current char is a duplicated char, current longest string stop at prev index. Check if the current is longer than prev longest string.
* Start from the next index of prev duplicated char, do it again.
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
		size_t currentSubStrLength = 0, lastSubStrLength = 0, strStartIndex = 0;;

		for (size_t i = 0; strStartIndex + currentSubStrLength < _str.length() && i < _str.length(); i++)
		{
			// check next chara repeat or not
			char currentChar = _str[i];
			if (charAndPos.empty() || charAndPos.find(currentChar) == charAndPos.end())
			{
				charAndPos.insert(std::pair<char, int>(currentChar, i));
				currentSubStrLength++;
			}
			else // find repeat char, reset i(check pos) to the repeat char's previous pos
			{
				i = charAndPos[currentChar];
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