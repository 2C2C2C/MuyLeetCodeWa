#pragma once

/*
70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/
*/

class Problem70
{
public:
	static int climbStairs(int n)
	{
		if (n <= 3)
			return n;

		int result = 3, last = 2, temp = 0;
		for (int i = 4; i <= n; i++)
		{
			temp = result;
			result += last;
			last = temp;
		}

		return result;
	}
};