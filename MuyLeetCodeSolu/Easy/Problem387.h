#pragma once

/*
387. First Unique Character in a String
https://leetcode.com/problems/first-unique-character-in-a-string/
*/

#include<iostream>
#include<math.h>
#include<algorithm>
#include<map>

class Problem387
{
public:
	static int firstUniqChar(std::string s)
	{
		int result = -1;
		bool findLah = false;
		std::map<char, int> countChecker; // on stack

		for (unsigned int i = 0; i < s.length(); i++)
		{
			if (countChecker.find(s[i]) == countChecker.end())
				countChecker.insert({ s[i],i });
			else
				countChecker[s[i]] = -1;
		}

		std::map<char, int>::iterator checkerIt;
		for (checkerIt = countChecker.begin(); checkerIt != countChecker.end(); checkerIt++)
		{
			if (checkerIt->second >= 0)
			{
				if (!findLah)
				{
					findLah = true;
					result = checkerIt->second;
				}
				else if (checkerIt->second < result)
					result = checkerIt->second;
			}
		}

		if (findLah)
			return result;
		else
			return -1;
	}
};

