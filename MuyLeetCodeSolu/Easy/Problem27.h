#pragma once

/*
27. Remove Element
https://leetcode.com/problems/remove-element/
*/

#include <vector>

class Problem27
{
public:
	static int removeElement(std::vector<int>& nums, int val)
	{
		if (nums.size() <= 0)
			return 0;
		std::vector<int> result;
		int current = val;
		int length = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			// remove this element
			if (nums[i] != val)
			{
				result.push_back(nums[i]);
				length++;
			}
		}
		nums = result;
		return length;
	}
};