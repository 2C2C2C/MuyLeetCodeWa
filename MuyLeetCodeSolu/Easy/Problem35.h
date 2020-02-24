#pragma once

/*
35. Search Insert Position
https://leetcode.com/problems/search-insert-position/
*/

#include <vector>

class Problem35
{
public:
	static int searchInsert(std::vector<int>& nums, int target)
	{
		std::vector<int> result;
		int index;
		bool inLa = false;
		for (int i = 0; i < nums.size(); i++)
		{
			if (target <= nums[i] && !inLa)
			{
				result.push_back(target);
				index = i;
				inLa = true;
			}
			result.push_back(nums[i]);
		}
		if (!inLa)
		{
			index = nums.size();
			result.push_back(target);
		}
		nums = result;
		return index;
	}
};