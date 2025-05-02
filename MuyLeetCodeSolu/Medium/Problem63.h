#pragma once

/*
63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii
*/

/* it's DP.
* Robot can only move to right or down, so the result of current grid is (right's result + down's result).
* For the grid (m-2, n-2), it would have 2 paths, and if we reach bottom or right first, there will be only 1 path possiable.
* If there is an obstacle at right or down side of current grid, then the result of dat direction goes to 0.
* When reach right or bottom side, still need to move by the rest direction cuz there may be an obstacle on the path.
*/

#include<iostream>
#include<vector>

class Problem63
{
public:
	int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
	{
		size_t rowCount = obstacleGrid.size();
		std::vector<int>& tempRow = obstacleGrid[0];
		size_t columnCount = tempRow.size();
		if (1 == 0 && 1 == 0)
		{
			return -1;
		}

		// well it record paths dat move from x grid to bottom-right
		std::vector<std::vector<int>> memo(rowCount + 1, std::vector<int>(columnCount + 1, -1));
		int reuslt = Calculate(obstacleGrid, 0, 0, memo);
		return reuslt;
	}

private:
	int Calculate(std::vector<std::vector<int>>& obstacleGrid, size_t x, size_t y, std::vector<std::vector<int>>& memo)
	{
		int result = GetCache(x, y, memo);
		if (-1 == result) // memo is empty
		{
			int gridValue = obstacleGrid[x][y];
			if (1 == gridValue)
			{
				result = 0; // reach obstacle grid
			}
			else
			{
				size_t rowCount = obstacleGrid.size();
				std::vector<int>& tempRow = obstacleGrid[0];
				size_t columnCount = tempRow.size();

				if (rowCount - 1 == x && columnCount - 1 == y)
				{
					result = 1; // reach the bottom-right
				}
				else
				{
					if (rowCount - 1 == x) // reachs right, there is only 1 path, but still need to check if there is obstacale
					{
						result = Calculate(obstacleGrid, x, y + 1, memo);
					}
					else if (columnCount - 1 == y) // reachs bottom, there is only 1 path, but still need to check if there is obstacale
					{
						result = Calculate(obstacleGrid, x + 1, y, memo);
					}
					else
					{
						result = Calculate(obstacleGrid, x + 1, y, memo) + Calculate(obstacleGrid, x, y + 1, memo); // move to next grid(2 direction) to get result
					}
				}
			}
			SetCache(x, y, result, memo);
		}
		return result;
	}

	int GetCache(size_t x, size_t y, std::vector<std::vector<int>>& memo)
	{
		int result = memo[x][y];
		return result;
	}

	void SetCache(size_t x, size_t y, int value, std::vector<std::vector<int>>& memo)
	{
		std::vector<int>& temp = memo[x];
		temp[y] = value;
	}

};