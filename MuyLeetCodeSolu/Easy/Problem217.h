#pragma once

/*
217. Contains Duplicate
https://leetcode.com/problems/contains-duplicate/
*/

#include <vector>
#include <set>

class Problem127
{
public:
	static bool containsDuplicate(std::vector<int>& nums)
	{
		if (nums.size() < 2) return false;

		std::set<int>tempSet{ nums.begin(),nums.end() };
		bool result = false;
		//unsigned int i = 0, j = 0;

		if (tempSet.size() < nums.size())
			result = true;

		return result;

		//for (i = 0; i < nums.size(); i++)
		//{
		//	for (j = 0; j < nums.size() - i - 1; j++)
		//	{
		//		if (nums[j] == nums[j + 1])
		//		{
		//			result = true;
		//			break;
		//		}
		//		else if (nums[j] > nums[j + 1])
		//			std::swap(nums[j], nums[j + 1]);
		//	}
		//	if (result)
		//		break;
		//}

		//if (!result)
		//	for (i = 0; i < nums.size() - 1; i++)
		//	{
		//		if (nums[i] == nums[i + 1])
		//		{
		//			result = true;
		//			break;
		//		}
		//	}

		//return result;
	}
};