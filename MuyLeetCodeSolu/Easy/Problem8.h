#pragma once

/*
8. String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/
*/

#include <iostream>

class Problem8
{
public:
	static int myAtoi(std::string _inputStr)
	{
		// check first, than cut
		std::string numStr;
		int result = 0;
		int i = 0;

		// cunt empty head
		while (i < _inputStr.length())
		{
			// cal empty counts
			if (_inputStr[i] == ' ')
				i++;
			else
				break;
		}
		numStr = _inputStr.substr(i, _inputStr.length() - i);

		bool isNeg = 0;
		// ascii 0~9 => 48~57

		if (numStr[0] == '+' || numStr[0] == '-')
		{
			if (numStr[1] < '0' || numStr[1] > '9')
				return 0;
			else
				isNeg = (numStr[0] == '-');
		}
		else if (numStr[0] < '0' || numStr[0] > '9')
			return 0;

		// cut sign and 0
		i = 0;
		if (isNeg || numStr[0] == '+')
			i++;
		do
		{
			if (numStr[i] != '0')
				break;
		} while (++i < numStr.length());
		numStr = numStr.substr(i, numStr.length() - i);

		// cut back
		i = 0;
		while (i < numStr.length())
		{
			if (numStr[i] >= '0' && numStr[i] <= '9')
				i++;
			else
				break;
		}
		numStr = numStr.substr(0, i);

		// cal 
		i = 0;
		int temp = 0;
		while (i < numStr.length())
		{
			// check overflow first
			if (!isNeg) // check positive overflow
			{
				if (result > INT32_MAX / 10)
					return INT32_MAX;
			}
			else // check negative overflow
			{
				if (result < INT32_MIN / 10)
					return INT32_MIN;
			}

			// add and check
			if (isNeg)
			{
				temp = (result * 10 + INT32_MAX);
				if ((result * 10 + INT32_MAX) > (numStr[i] - '0' - 1))
					result = result * 10 - (numStr[i] - '0');
				else
					return INT32_MIN;
			}
			else
			{
				temp = (INT32_MAX - result * 10);
				if ((INT32_MAX - result * 10) > (numStr[i] - '0'))
					result = result * 10 + (numStr[i] - '0');
				else
					return INT32_MAX;
			}
			i++;
		}

		return result;
	}

};

