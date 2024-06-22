#pragma once

/*
67. Add Binary
https://leetcode.com/problems/add-binary/
*/

#include <iostream>
using namespace std;

class Problem67
{
public:
	static string addBinary(string a, string b)
	{
		unsigned int strASize = a.size();
		unsigned int strBSize = b.size();
		std::string result = "";

		unsigned int i = 0, tempCarry = 0, tempSum;
		while (true)
		{
			bool strAEnd = i >= strASize;
			bool strBEnd = i >= strBSize;
			tempSum = 0;
			if (!strAEnd)
			{
				tempSum += a[strASize - i - 1] - '0';
			}
			if (!strBEnd)
			{
				tempSum += b[strBSize - i - 1] - '0';
			}
			int temp = tempSum + tempCarry;
			if (temp > 1)
			{
				bool tempMod2Check = (temp % 2) > 0;
				result.push_back(tempMod2Check ? '1' : '0');
				temp = tempMod2Check ? temp - 1 : temp;
				tempCarry = temp / 2;
			}
			else if (temp <= 1)
			{
				if (temp > 0)
				{
					result.push_back((char)('0' + temp));
				}
				else if (!strAEnd || !strBEnd)
				{
					result.push_back((char)('0'));
				}
				tempCarry = 0;
			}
			++i;
			if (tempCarry == 0 && strAEnd && strBEnd)
			{
				break;
			}
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

};