#pragma once

#include<iostream>

class Problem371
{
public:
	static int getSum(int a, int b)
	{
		int32_t tempA = a, tempB = b, tempC = 0, current = 0;
		unsigned int i = 0;
		int result = 0;

		while (i < 32)
		{
			if (tempA & 1 == 1)
				current++;
			if (tempB & 1 == 1)
				current++;

			if (current == 1)
			{
				current = 1;
				current = current << i;
				tempC += current;
				current = 0;
			}
			else if (current == 2)
				current = 1;
			else if (current == 3)
			{
				current = 1;
				current = current << i;
				tempC += current;
				current = 1;
			}

			tempA = tempA >> 1;
			tempB = tempB >> 1;
			i++;
		}

		result = tempC;
		return result;
	}
};

