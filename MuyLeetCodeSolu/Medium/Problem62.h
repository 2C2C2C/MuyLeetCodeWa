#pragma once

/*
62. Unique Paths
https://leetcode.com/problems/unique-paths/
*/

/* it's DP.
* Robot can only move to right or down, so the result of current grid is (right's result + down's result).
* For the grid (m-2, n-2), it would have 2 paths, and if we reach bottom or right first, there will be only 1 path.
*/

#include<iostream>
#include<vector>

class Problem62
{
public:
	int uniquePaths(int m, int n)
	{
		if (1 == m && 1 == n)
		{
			return -1;
		}

		std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, -1));
		int result = Calculate(m, n, memo);
		return result;
	}

private:

	int Calculate(int m, int n, std::vector<std::vector<int>>& memo)
	{
		int result = GetCache(m, n, memo);
		if (-1 == result)
		{
			if (1 == m || 1 == n) // when horizontal or vertical dist is 1, there will be only 1 path(go throught another direction)
			{
				result = 1;
			}
			else
			{
				result = Calculate(m - 1, n, memo) + Calculate(m, n - 1, memo);
			}
			SetCache(m, n, result, memo);
		}
		return result;
	}

	int GetCache(int m, int n, std::vector<std::vector<int>>& memo)
	{
		int result = memo[m][n];
		return result;
	}

	void SetCache(int m, int n, int value, std::vector<std::vector<int>>& memo)
	{
		std::vector<int>& temp = memo[m];
		temp[n] = value;
	}

};