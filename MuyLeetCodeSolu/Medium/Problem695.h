#pragma once

/*
695. Max Area of Island
https://leetcode.com/problems/max-area-of-island/description/
*/

/* Find a valid grid(1 == value);
* BFS
* Calculate area from this grid by BFS(Use a queue, mark current grid and push all the next accessable grid).
* Compare result.
*/

#include <vector>
#include <queue>

struct NodeIndex
{
	size_t rowIndex;
	size_t columnIndex;
};

class Problem695
{
public:
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
	{
		int result = 0;
		for (size_t i = 0, rowCount = grid.size(); i < rowCount; i++)
		{
			std::vector<int>& rowContent = grid[i];
			for (size_t j = 0, columnCount = rowContent.size(); j < columnCount; j++)
			{
				int gridValue = rowContent[j];
				if (0 == gridValue)
				{
					continue;
				}
				std::queue<NodeIndex> toVisit;
				NodeIndex node;
				node.rowIndex = i;
				node.columnIndex = j;
				toVisit.push(node);

				int tempArea = checkAndMarkIsland(grid, toVisit);
				if (tempArea > result)
				{
					result = tempArea;
				}
			}
		}
		return result;
	}

private:

	int checkAndMarkIsland(std::vector<std::vector<int>>& grid, std::queue<NodeIndex>& toVisit)
	{
		int result = 0;
		if (toVisit.empty())
		{
			return result;
		}

		size_t rowCount = grid.size();
		size_t columnCount = grid[0].size();
		do
		{
			NodeIndex node = toVisit.front();
			toVisit.pop();
			size_t rowIndex = node.rowIndex;
			size_t columnIndex = node.columnIndex;
			std::vector<int>& rowContent = grid[rowIndex];
			int gridContent = rowContent[columnIndex];
			if (0 == gridContent)
			{
				continue;;
			}

			rowContent[columnIndex] = 0; // mark invalid as visited
			++result;
			// visit 4 dir grids
			if (0 < columnIndex) // vist left
			{
				NodeIndex left;
				left.rowIndex = rowIndex;
				left.columnIndex = columnIndex - 1;
				toVisit.push(left);
			}
			if (columnCount - 1 > columnIndex) // vist right
			{
				NodeIndex right;
				right.rowIndex = rowIndex;
				right.columnIndex = columnIndex + 1;
				toVisit.push(right);
			}
			if (0 < rowIndex) // visit up
			{
				NodeIndex up;
				up.rowIndex = rowIndex - 1;
				up.columnIndex = columnIndex;
				toVisit.push(up);
			}
			if (rowCount - 1 > rowIndex) // visit down
			{
				NodeIndex down;
				down.rowIndex = rowIndex + 1;
				down.columnIndex = columnIndex;
				toVisit.push(down);
			}

		} while (!toVisit.empty());

		return result;
	}
};