#pragma once

/*
202. Happy Number
https://leetcode.com/problems/happy-number/
*/

#include <iostream>

class Problem202
{
public:
	static bool isHappy(int n)
	{
		bool result = false, flag = false;
		int tempA = n, tempB = 0;

		while (!result)
		{
			tempB = 0;
			while (tempA != 0)
			{
				tempB += pow((tempA % 10), 2);
				tempA /= 10;
			}
			tempA = tempB;

			if (tempA < 10)
			{
				switch (tempA)
				{
				case 1:
				case 7:
					result = true;
					return result;
				default:
					return result;
					break;
				}
			}
			// how to know it will infinite loop ?
			// 1 , 7 will end this shit
		}
		return result;
	}

};