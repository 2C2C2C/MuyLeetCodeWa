#pragma once

/*
17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

// 2(abc) - 9(wxyz)

#include <vector>
#include <map>

class Problem17
{
public:
	static std::vector<std::string> letterCombinations(std::string digits)
	{
		if (digits.length() < 1)
		{
			std::vector<std::string> emptyResult;
			return emptyResult;
		}

		std::vector<std::string> result, tempRes;
		int i = 0, j = 0, k = 0;
		std::string tempStrA = "", tempStrB = "";

		// create char - string map
		std::map<char, std::string> charMap =
		{
			{'2',"abc"},
			{'3',"def"},
			{'4',"ghi"},
			{'5',"jkl"},
			{'6',"mno"},
			{'7',"pqrs"},
			{'8',"tuv"},
			{'9',"wxyz"},
		};

		// create strings
		tempStrA.resize(digits.length());
		for (i = 0; i < digits.length(); i++)
		{
			tempStrB = charMap[digits[i]];
			tempRes = std::vector<std::string>(result);
			for (j = 0; j < tempStrB.length(); j++)
			{
				if (tempRes.size() == 0)
				{
					tempStrA[i] = tempStrB[j];
					result.push_back(tempStrA);
				}
				else
				{
					for (k = 0; k < tempRes.size(); k++)
					{
						(tempRes[k])[i] = tempStrB[j];
						if (j == 0)
							result[k] = tempRes[k];
						else
							result.push_back(tempRes[k]);
					}
				}
			}
		}

		return result;
	}


};