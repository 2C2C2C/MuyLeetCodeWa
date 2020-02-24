#pragma once

/*
1. two sum
https://leetcode.com/problems/two-sum/
*/

#include <vector>

class Problem1
{
public:
	static std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		int i = 0, j = 0;
		std::vector<int> ans;
		// check num from pos i
		for (i = 0; i < nums.size() - 1; i++)
		{
			for (j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}
		}
		return ans;
	}
};