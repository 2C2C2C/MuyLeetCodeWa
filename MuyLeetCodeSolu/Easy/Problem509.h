#pragma once

/*
509. Fibonacci Number
https://leetcode.com/problems/fibonacci-number/
*/

/*
*
*/

class Problem509
{
public:
	int fib(int n)
	{
		switch (n)
		{
		case 0:return 0;
		case 1:return 1;
		default:
			break;
		}

		int nMinus1 = 1;
		int nMinus2 = 0;
		for (int i = 2; i <= n; i++)
		{
			int temp = nMinus1 + nMinus2;
			nMinus2 = nMinus1;
			nMinus1 = temp;
		}
		return nMinus1;
	}
};