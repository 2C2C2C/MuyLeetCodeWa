#pragma once

/*
20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/\
*/

#include <iostream>
#include <stack>

class Problem20
{
public:
	static bool isValid(std::string s)
	{
		char upWa[] = { '(','[','{' };
		char downWa[] = { ')',']','}' };
		bool upTrue_downFalse = false;
		std::stack<int> matchStack;

		for (int i = 0; i < s.length(); i++)
		{
			// check input char if it is left bracket
			for (int k = 0; k < sizeof(upWa); k++)
			{
				if (s[i] == upWa[k])
				{
					matchStack.push(k);
					upTrue_downFalse = true;
				}
			}
			if (!upTrue_downFalse)
			{
				// input char is right bracket, try match last input open bracket
				if (matchStack.empty())
					return false;
				for (int l = 0; l < sizeof(downWa); l++)
				{
					if (s[i] == downWa[l])
					{
						if (matchStack.size() <= 0)
							return false;
						else if (matchStack.top() == l)
							matchStack.pop();
						else
							return false;
					}
				}
			}
			upTrue_downFalse = false;
		}
		return matchStack.empty();
	}
};