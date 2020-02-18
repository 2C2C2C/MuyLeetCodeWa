#pragma once

/*
204. Count Primes
https://leetcode.com/problems/count-primes/
*/

#include <iostream>

class Problem204
{
public:
	static int countPrimes(int n)
	{
		if (n < 4)
		{
			if (n == 3)
				return 1;
			else
				return 0;
		}

		int result = 0;
		int limit = std::sqrt(n);
		int* tempArr = new int[n + 1]{};
		unsigned int i = 0, j = 0;

		// set -1 as non-prime flag
		for (i = 2; i <= limit; i++)
		{
			if (tempArr[i] == 0)
			{
				j = 2 * i;
				while (j < n)
				{
					tempArr[j] = -1;
					j += i;
				}
			}
		}

		for (i = 2; i < n; i++)
		{
			if (tempArr[i] == 0)
				result++;
		}

		return  result;
	}
};