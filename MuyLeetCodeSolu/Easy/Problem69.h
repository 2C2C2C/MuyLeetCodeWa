#pragma once

/*
69. Sqrt(x)
https://leetcode.com/problems/sqrtx/
*/

class Problem69
{
public:
	static int mySqrt(int x)
	{
		if (x <= 1)
			return x;
		int temp = x / 2, result = 0;
		int i = 1;
		while (i <= temp)
		{
			if (i >= 46341)
				return i - 1;
			if (i*i > x)
			{
				result = i - 1;
				return result;
			}
			i++;
		}
		result = i - 1;
		return result;
	}

};