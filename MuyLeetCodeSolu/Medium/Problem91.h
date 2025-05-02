#pragma once

/*
91. Decode Ways
https://leetcode.com/problems/decode-ways
*/

/*
*
*/

#include<string>
#include<vector>

class Problem91
{
public:
	int numDecodings(std::string s)
	{
		size_t sourceLength = s.length();
		std::vector<size_t> memo(sourceLength, 0);
		if (1 == sourceLength)
		{
			return s == "0" ? 0 : 1;
		}
		if (canDecode(s[0]))
		{
			memo[0] = 1;
			size_t prevCharType = TYPE_2;
			for (size_t i = 1; i < sourceLength; ++i)
			{
				char currentChar = s[i];
				bool canDecodeWithPrevChar = canDecode(s[i - 1], currentChar);
				if (canDecode(currentChar)) // if current char can be directly decoded
				{
					if (canDecodeWithPrevChar)
					{
						if (TYPE_2 == prevCharType || TYPE_1 == prevCharType)
						{
							if (1 == i)
							{
								memo[i] = memo[i - 1] + 1;
							}
							else
							{
								memo[i] = memo[i - 1] + memo[i - 2];
							}
							prevCharType = TYPE_2;
						}
					}
					else // can only decode self, do not add result
					{
						memo[i] = memo[i - 1];
						prevCharType = TYPE_1;
					}
				}
				else // current char can not be directly decoded
				{
					if ((TYPE_2 == prevCharType || TYPE_1 == prevCharType) && canDecodeWithPrevChar) // current char can ONLY be decoded with prev char
					{
						if (1 == i) // edge case
						{
							memo[i] = 1;
						}
						else
						{
							memo[i] = memo[i - 1] = memo[i - 2];
						}
						prevCharType = TYPE_3;
					}
					else if (sourceLength - 1 == i) // this char will explode
					{
						memo[i] = memo[i - 1];
						break;
					}
					else
					{
						return 0;
					}
				}
			}
		}
		return memo[sourceLength - 1];
	}

private:
	/* There is not possiable dat a char can only be decode with next char :) */
	// Only self
	const size_t TYPE_1 = 1;
	// Self and with prev char
	const size_t TYPE_2 = 2;
	// Only with prev char
	const size_t TYPE_3 = 3;

	bool canDecode(char prev, char current)
	{
		bool result = false;
		switch (prev)
		{
		case '1':
			result = '0' <= current && '9' >= current;
			break;
		case '2':
			result = '0' <= current && '6' >= current;
			break;
		default:
			break;
		}
		return result;
	}

	bool canDecode(char single)
	{
		return !('0' == single);
	}
};