#pragma once

/*
14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/
*/

#include <iostream>
#include <vector>

class Problem14
{
public:
	static std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		std::string result = "";
		if (strs.size() <= 0)
			return result;
		char currentWa = ' ';
		for (int i = 0; i < strs[0].length(); i++)
		{
			currentWa = strs[0][i];// get 1st str's char at i pos
			for (int j = 1; j < strs.size(); j++)
			{
				// use current char to check other str at i pos
				if (i <= strs[j].length() - 1) // check length
				{
					if (currentWa != strs[j][i])
					{
						return result;
					}
				}
				else
					return result;
			}
			result += currentWa;
		}
		return result;
	}
};