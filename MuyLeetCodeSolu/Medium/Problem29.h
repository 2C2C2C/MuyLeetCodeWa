#pragma once

/*
29. Divide Two Integers
https://leetcode.com/problems/divide-two-integers/
*/

#include <iostream>

class Problem29
{
public:
	static int divide(int dividend, int divisor)
	{
		long dividendL = dividend, divisorL = divisor, resultL = 0;
		bool needRev = (dividendL > 0) ^ (divisorL > 0);

		dividendL = abs(dividendL);
		divisorL = abs(divisorL);

		if (0 == dividendL || 0 == divisorL || dividendL < divisorL)
			return (int)resultL;

		long testCount = 0;
		long testNum = 0;
		while (dividendL >= divisorL)
		{
			// attempt
			testCount = 1;
			testNum = divisorL;
			while (dividendL >= (testNum << 1)) // make it faster
			{
				testNum = testNum << 1;
				testCount = testCount << 1; // *=2
			}
			resultL += testCount;
			dividendL -= testNum;
		}


		int result = 0;
		if (needRev)
			resultL = -resultL;

		if (resultL > INT32_MAX)
			result = INT32_MAX;
		else if (resultL < INT32_MIN)
			result = INT32_MIN;
		else
			result = (int)resultL;

		return result;
	}
};