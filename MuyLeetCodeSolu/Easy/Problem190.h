#pragma once

/*
190. Reverse Bits
https://leetcode.com/problems/reverse-bits/
*/

#include <iostream>

// how to operate bit in cpp???
class Problem190
{
public:

	// 00000010100101000001111010011100
	// &
	// 00000000000000000000000000000001 (int32 1)
	// = 
	// 00000000000000000000000000000000

	static uint32_t reverseBits(uint32_t n)
	{
		uint32_t result = 0;
		uint32_t temp = n;
		for (unsigned int i = 0; i < 32; i++)
		{
			if (temp & 1 == 1)
				result = (result << 1) + 1;
			else // if temp & 1 == 0 
				result = result << 1; // left move auto add 0
			temp = temp >> 1; // move temp to left
		}
		return result;
	}
};