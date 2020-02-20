#pragma once

/*
22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/
*/

#include <vector>
// TODO : not finish
class Problem22
{
public:
	static std::vector<std::string> generateParenthesis(int n)
	{
		// { ()() }
		std::vector<std::string> result;
		std::string tempStr = "";
		unsigned int i = 0;

		for (i = 0; i < n; i++)
		{
			//tempStr()
		}

		return result;
	}

	static std::string GetAStr(int count, bool foldTogether)
	{
		char* chArr = new char[count * 2];
		unsigned int i = 0;
		if (foldTogether)
		{
			// like ((()))
			while (i < count)
				chArr[i++] = '(';
			while (i < count * 2)
				chArr[i++] = ')';
		}
		else
		{
			// like ()()()
			while (i < count * 2)
			{
				if (i % 2 == 0)
					chArr[i] = '(';
				else
					chArr[i] = ')';
				i++;
			}
		}

		std::string resStr(chArr); // TODO : why goes wrong
		resStr.resize(count * 2); // ???
		return resStr;
	}


};