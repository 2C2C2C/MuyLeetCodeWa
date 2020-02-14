#pragma once

class Problem326
{
public:
	static bool isPowerOfThree(int n)
	{
		while (n > 3)
		{
			if (n % 3 == 0)
				n /= 3;
			else
				return false;
		}

		return (n == 1 || n == 3);
	}

};

