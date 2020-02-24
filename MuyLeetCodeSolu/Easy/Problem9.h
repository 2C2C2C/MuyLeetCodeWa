#pragma once

/*
9. Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/

#include <iostream>

class Problem9
{
public:
	static bool isPalindrome(int x)
	{
		// check negative number and 0
		if (x < 0)
			return false; //
		else if (x == 0)
			return true;

		int rev = 0; // a number used to check Palindrome 
		bool test = false;
		int times = (int)log10(x) + 1;
		if (times % 2 != 0)// if odd, else even
		{
			times++;
			test = true;
		}
		times /= 2;

		// cut original number, and build half Palindrome number
		for (int i = 0; i < times; i++)
		{
			rev = rev * 10 + (x % 10);// move left, add new
			if (i + 1 != times) // move right
				x /= 10;
			else if (!test)
				x /= 10;
		}

		return (x == rev);
	}
};

