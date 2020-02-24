#pragma once

/*
26. Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <vector>

class Problem26
{
public:
	static int removeDuplicates(std::vector<int>& nums)
	{
		std::vector<int> result;
		if (nums.size() <= 0)
			return 0;
		// push first element
		int current = nums[0];
		result.push_back(current);

		int length = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			// check if repeat
			if (current != nums[i])
			{
				length++;
				current = nums[i];
				result.push_back(current);
			}
		}
		nums = result;
		return length;
	}

};