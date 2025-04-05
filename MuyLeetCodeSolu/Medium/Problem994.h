#pragma once

/*
994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/description/
*/

/*
* Traverse all grid first, collect all rotten oranges into a queue and check if there is any fresh orange in grids.
* If no fresh, return 0 (already done).
* Has fresh, if no rotten orange return -1 (impossible).
* Let prev collected rotten oranges do expand around, fresh orange around will be rotten.
* Push all got rotted oranges into the queue from prev wave of expands.
* Repeat above 2 steps until queue is empty.
* Check grids again to see if there is any fresh orange.
* If so, return -1 (impossible).
* Else, return repeat count of dat 2 steps (done).
*/

#include <vector>
#include <queue>

struct GridIndex
{
	size_t rowIndex;
	size_t columnIndex;
	GridIndex() : rowIndex(0), columnIndex(0) {}
	GridIndex(size_t x, size_t y) : rowIndex(x), columnIndex(y) {}

	inline bool operator==(const GridIndex& other) const
	{
		return this->rowIndex == other.rowIndex && this->columnIndex == other.columnIndex;
	}
};

class Problem994
{
public:
	int orangesRotting(std::vector<std::vector<int>>& grids)
	{
		std::queue<GridIndex> toDoExpand;
		bool hasFreshOrange = false;
		for (size_t i = 0, rowCount = grids.size(); i < rowCount; i++)
		{
			std::vector<int>& rowContent = grids[i];
			for (size_t j = 0, columnCount = rowContent.size(); j < columnCount; j++)
			{
				if (2 == rowContent[j])
				{
					GridIndex tempGrid(i, j);
					toDoExpand.push(tempGrid);
				}
				hasFreshOrange = hasFreshOrange || 1 == rowContent[j];
			}
		}


		if (hasFreshOrange)
		{
			int expandTime = -1;
			if (toDoExpand.empty())
			{
				return expandTime;
			}

			// expand rot
			size_t rowCount = grids.size(), columnCount = grids[0].size();
			size_t turnGridCount = toDoExpand.size();
			do
			{
				GridIndex currentGrid = toDoExpand.front();
				toDoExpand.pop();

				GridIndex left = MoveLeft(currentGrid);
				if (CanBeRotten(grids, left))
				{
					grids[left.rowIndex][left.columnIndex] = 2;
					toDoExpand.push(left);
				}

				GridIndex right = MoveRight(currentGrid, columnCount);
				if (CanBeRotten(grids, right))
				{
					grids[right.rowIndex][right.columnIndex] = 2;
					toDoExpand.push(right);
				}

				GridIndex up = MoveUp(currentGrid);
				if (CanBeRotten(grids, up))
				{
					grids[up.rowIndex][up.columnIndex] = 2;
					toDoExpand.push(up);
				}

				GridIndex down = MoveDown(currentGrid, rowCount);
				if (CanBeRotten(grids, down))
				{
					grids[down.rowIndex][down.columnIndex] = 2;
					toDoExpand.push(down);
				}

				if (0 == --turnGridCount)
				{
					++expandTime;
					turnGridCount = toDoExpand.size();
				}
			} while (!toDoExpand.empty());

			// final check, if there is orange not be rotten
			for (size_t i = 0, rowCount = grids.size(); i < rowCount; i++)
			{
				std::vector<int>& rowContent = grids[i];
				for (size_t j = 0, columnCount = rowContent.size(); j < columnCount; j++)
				{
					GridIndex tempGrid(i, j);
					if (CanBeRotten(grids, tempGrid))
					{
						return -1;
					}
				}
			}

			return expandTime;
		}

		// source has no fresh orange case
		return 0;
	}

private:
	bool CanBeRotten(std::vector<std::vector<int>>& grids, GridIndex gridIndex)
	{
		int temp = grids[gridIndex.rowIndex][gridIndex.columnIndex];
		return 1 == temp; // 0 empty, 2 rotten :)
	}

	// if grid move out of bounds, just return source grid since source grid must be visited :)

	GridIndex MoveLeft(GridIndex source)
	{
		return 0 == source.columnIndex ? source : GridIndex(source.rowIndex, source.columnIndex - 1);
	}

	GridIndex MoveRight(GridIndex source, size_t columnCount)
	{
		return columnCount - 1 == source.columnIndex ? source : GridIndex(source.rowIndex, source.columnIndex + 1);
	}

	GridIndex MoveUp(GridIndex source)
	{
		return 0 == source.rowIndex ? source : GridIndex(source.rowIndex - 1, source.columnIndex);
	}

	GridIndex MoveDown(GridIndex source, size_t rowCount)
	{
		return rowCount - 1 == source.rowIndex ? source : GridIndex(source.rowIndex + 1, source.columnIndex);
	}
};