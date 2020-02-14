#pragma once

/*
191. Number of 1 Bits
https://leetcode.com/problems/number-of-1-bits
*/

#include <iostream>

class Problem191
{
public:
	static int hammingWeight(uint32_t n)
	{
		int result = 0;
		for (unsigned int i = 0; i < 32; i++)
		{
			if (n & 1 == 1)
				result++;
			n = n >> 1;
		}
		return result;
	}

};

