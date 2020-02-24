#pragma once

/*
66. Plus One
https://leetcode.com/problems/plus-one/
*/

#include <vector>

class Problem66
{
public:
	static std::vector<int> plusOne(std::vector<int>& digits)
	{
		//std::vector<int> result;
		digits.back()++;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] > 9)
			{
				digits[i] %= 10;
				if (i == 0)
					digits.insert(digits.begin(), 1);
				else
					digits[i - 1]++;
			}
		}
		return digits;
	}
};