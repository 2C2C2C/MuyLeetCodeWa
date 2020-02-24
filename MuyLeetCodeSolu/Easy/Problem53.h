#pragma once

/*
53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/
*/

#include <vector>

class Problem53
{
public:
	static int maxSubArray(std::vector<int>& _nums)
	{
		if (_nums.size() == 0)
			return 0;
		else if (_nums.size() == 1)
			return _nums.back();

		int sum = 0, sumTemp = 0;
		sum = sumTemp = _nums.front();
		int subArrLength = 1;

		for (int ix = 0; ix < _nums.size(); ix++)
		{
			sumTemp = 0;
			subArrLength = 0;
			while (subArrLength + ix < _nums.size())
			{
				// scan for array length
				if (_nums[ix + subArrLength] / 2 + sumTemp / 2 >= INT_MAX)
					sumTemp = INT_MAX;
				else if ((_nums[ix + subArrLength] < (INT_MIN / 2) - 1 && sumTemp < (INT_MIN / 2) - 1))
					sumTemp = INT_MIN;
				else
					sumTemp += _nums[ix + subArrLength];

				subArrLength++;
				sum = std::max(sum, sumTemp);
			}
			//std::cout << "test length " << ix << std::endl;
		}

		return sum;
	}
};