#pragma once

/*
300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence
*/

/* it's DP.
* Fill memo first (check and fill for every index).
* Fill memo by calculate the LIS from current index;
* current result(1) plus the next greater element's result, and look through all greater elements of rest, get the final result. Then put into memo.
*/

#include<vector>

class Problem300
{
public:
	int lengthOfLIS(std::vector<int>& nums)
	{
		int result;
		size_t numCount = nums.size();
		switch (numCount)
		{
		case 0: result = 0;
			break;
		case 1: result = 1;
			break;
		default:
			// fill memo
			std::vector<int> memo(numCount, -1);
			for (size_t i = 0; i < numCount; i++)
			{
				if (-1 == memo[i])
				{
					FillMemo(nums, i, memo);
				}
			}
			result = -1;
			for (size_t i = 0, memoLength = memo.size(); i < memoLength; i++)
			{
				int temp = memo[i];
				if (temp > result)
				{
					result = temp;
				}
			}
			break;
		}
		return result;
	}

private:
	int FillMemo(std::vector<int>& nums, size_t currentIndex, std::vector<int>& memo)
	{
		if (-1 == memo[currentIndex]) // need to fill memo data
		{
			int currentNum = nums[currentIndex];
			int result = 1;
			for (size_t i = currentIndex + 1, numCount = nums.size(); i < numCount; i++)
			{
				if (currentNum < nums[i])
				{
					int tempResult = memo[currentIndex] = 1 + FillMemo(nums, i, memo);
					if (tempResult > result)
					{
						result = tempResult;
					}
				}
			}
			return memo[currentIndex] = result;
		}
		return memo[currentIndex];
	}

};