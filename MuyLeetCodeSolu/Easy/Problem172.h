#pragma once

/*
172. Factorial Trailing Zeroes
https://leetcode.com/problems/factorial-trailing-zeroes
*/

class Problem172
{
public:
	static int trailingZeroes(int n)
	{
		int result = 0;

		while (n > 1)
		{
			result += n / 5;
			n /= 5;
		}

		return result;
	}
};