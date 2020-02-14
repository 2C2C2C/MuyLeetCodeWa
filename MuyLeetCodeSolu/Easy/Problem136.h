#pragma once

/*
136. Single Number
https://leetcode.com/problems/single-number/s
*/

#include <vector>
#include <set>

class Problem136
{
public:
	static int singleNumber(std::vector<int>& nums)
	{
		std::set<int> tempSet;
		std::set<int> repeatSet;

		for (unsigned int i = 0; i < nums.size(); i++)
		{
			if (repeatSet.find(nums[i]) != repeatSet.end()) continue;

			if (tempSet.find(nums[i]) == tempSet.end())
			{
				tempSet.insert(nums[i]);
				continue;
			}
			else
			{
				tempSet.erase(nums[i]);
				repeatSet.insert(nums[i]);
			}
		}
		return *tempSet.begin();
	}


};

