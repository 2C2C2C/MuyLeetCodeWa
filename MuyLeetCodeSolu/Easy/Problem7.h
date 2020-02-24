#pragma once

/*
7. Reverse Integer
https://leetcode.com/problems/reverse-integer/
*/

#include <iostream>

class Problem7
{
public:
	static int reverse(int x)
	{
		int rst = 0, temp = 0;
		while (x != 0)
		{
			// add current number
			temp = x % 10;
			rst = rst * 10 + temp;

			// check if the result will overflow(int_max) in next round
			if (rst > INT_MAX / 10 && log10f(abs(x)) > 1)
				return 0;
			else if (rst > INT_MAX / 10) // no next round, return
				return rst;

			// check if the result will overflow(int_min) in next round
			if (rst < INT_MIN / 10 && log10f(abs(x)) > 1)
				return 0;
			else if (rst < INT_MIN / 10) // no next round, return
				return rst;

			x /= 10;
		}
		return rst;
	}
};
