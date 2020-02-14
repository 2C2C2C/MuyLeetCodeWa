#pragma once

/*
169. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

#include <vector>
#include <map>

class Problem169
{
public:
	static int majorityElement(std::vector<int>& nums)
	{
		if (nums.size() == 0) return 0;

		std::vector<int> tempNums = nums;
		std::map<int, int> tempChecks;
		int majority = 0, maxCount = -1;

		tempChecks.insert({ tempNums[0], 0 });
		for (int i = 0; i < tempNums.size(); i++)
		{
			if (tempChecks.find(tempNums[i]) == tempChecks.end())
				tempChecks.insert({ tempNums[i], 1 });
			else
				tempChecks[tempNums[i]]++;
		}

		// get maj
		std::map<int, int>::iterator it;
		for (it = tempChecks.begin(); it != tempChecks.end(); ++it)
		{
			if (maxCount < 0)
				majority = it->first;
			if (it->second > tempNums.size() / 2 && it->second > maxCount)
			{
				maxCount = it->second;
				majority = it->first;
			}
		}

		return majority;
	}
};