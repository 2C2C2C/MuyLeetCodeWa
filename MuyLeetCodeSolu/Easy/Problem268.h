#pragma once

/*
268. Missing Number
https://leetcode.com/problems/missing-number/
*/

#include <vector>

class  Problem268
{
public:
	// spaical XOR method

	// cuz (1 XOR 1 == 0) (X XOR 0 == X)
	// eg.  nums = {0,1,2,4,5}, size == 5
	// so missing = (0 XOR 1 XOR 2 XOR 4 XOR 5) XOR (0 XOR 1 XOR 2 XOR 3 XOR 4 XOR 5)

	// nums are from 0 to n
	static int missingNumber(std::vector<int>& nums)
	{
		int result = 0;
		unsigned i = 1;

		result = nums[0] ^ 0 ^ nums.size();
		for (unsigned int i = 1; i < nums.size(); i++)
			result = result ^ nums[i] ^ i;

		return result;
	}

};

