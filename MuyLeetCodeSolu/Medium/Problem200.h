#pragma once

/*
200. Number of Islands
https://leetcode.com/problems/number-of-islands/description/
*/

/* Do DFS search.
* Traverse all grids. When find a valid grid(value is '1'), start a DFS search from this grid.
* While in the search
*/

#include <vector>

class Problem200
{
public:
	static int numIslands(std::vector<std::vector<char>>& grid)
	{
		int result = 0;
		for (size_t i = 0, rowCount = grid.size(); i < rowCount; i++)
		{
			std::vector<char>& rowContent = grid[i];
			for (size_t j = 0, columnCount = rowContent.size(); j < columnCount; j++)
			{
				if ('1' == rowContent[j])
				{
					// do search from this grid
					MarkIslandVisited(grid, i, j);
					++result;
				}
			}
		}
		return result;
	}

private:
	static void MarkIslandVisited(std::vector<std::vector<char>>& grid, size_t rowIndex, size_t columnIndex)
	{
		std::vector<char>& rowContent = grid[rowIndex];
		char gridContent = rowContent[columnIndex];
		if ('1' == gridContent) // valid grid
		{
			rowContent[columnIndex] = '0'; // mark invalid as visited

			// visit 4 dir grids
			if (0 < columnIndex) // vist left
			{
				MarkIslandVisited(grid, rowIndex, columnIndex - 1);
			}
			if (rowContent.size() - 1 > columnIndex) // vist right
			{
				MarkIslandVisited(grid, rowIndex, columnIndex + 1);
			}

			if (0 < rowIndex) // visit up
			{
				MarkIslandVisited(grid, rowIndex - 1, columnIndex);
			}
			if (grid.size() - 1 > rowIndex) // visit down
			{
				MarkIslandVisited(grid, rowIndex + 1, columnIndex);
			}
		}
	}
};