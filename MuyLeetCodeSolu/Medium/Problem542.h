#pragma once

/*
542. 01 Matrix
https://leetcode.cn/problems/01-matrix/description/
*/

/*
* Traversal all grids. Collect all grids dat value == 0.
* When a grid value is not 0 (distance is not 0), start an expand search around current grid.
* Calculate result and fill in result grid.
*/

#include <vector>
#include <unordered_set>
#include <queue>

template <class T>
inline void hash_combine(std::size_t& s, const T& v)
{
	std::hash<T> h;
	s ^= h(v) + 0x9e3779b9 + (s << 6) + (s >> 2);
}

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

template <class T>
class GridIndexHash;

template<>
struct GridIndexHash<GridIndex>
{
	size_t operator()(GridIndex const& g) const
	{
		size_t result = 0;
		hash_combine(result, g.rowIndex);
		hash_combine(result, g.columnIndex);
		return result;
	}
};

class Problem542
{
public:
	std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
	{
		std::queue<GridIndex> toDoExpand;
		std::vector<std::vector<int>> result;
		for (size_t i = 0, rowCount = mat.size(); i < rowCount; i++)
		{
			std::vector<int>& rowContent = mat[i];
			std::vector<int> toAdd;
			for (size_t j = 0, columnCount = rowContent.size(); j < columnCount; j++)
			{
				if (0 == rowContent[j])
				{
					toAdd.push_back(0);
					GridIndex tempGrid(i, j);
					toDoExpand.push(tempGrid);
				}
				else
				{
					toAdd.push_back(-1);
				}
			}
			result.push_back(toAdd);
		}

		size_t rowCount = mat.size();
		size_t columnCount = mat[0].size();
		// do expand
		do
		{
			GridIndex grid = toDoExpand.front();
			toDoExpand.pop();
			int currentGridValue = result[grid.rowIndex][grid.columnIndex];

			GridIndex left = MoveLeft(grid);
			if (!isGridVisited(result, left))
			{
				result[left.rowIndex][left.columnIndex] = currentGridValue + 1;
				toDoExpand.push(left);
			}

			GridIndex right = MoveRight(grid, columnCount);
			if (!isGridVisited(result, right))
			{
				result[right.rowIndex][right.columnIndex] = currentGridValue + 1;
				toDoExpand.push(right);
			}

			GridIndex up = MoveUp(grid);
			if (!isGridVisited(result, up))
			{
				result[up.rowIndex][up.columnIndex] = currentGridValue + 1;
				toDoExpand.push(up);
			}

			GridIndex down = MoveDown(grid, rowCount);
			if (!isGridVisited(result, down))
			{
				result[down.rowIndex][down.columnIndex] = currentGridValue + 1;
				toDoExpand.push(down);
			}

		} while (!toDoExpand.empty());

		return result;
	}

private:
	bool isGridVisited(std::vector<std::vector<int>>& check, GridIndex grid)
	{
		int temp = check[grid.rowIndex][grid.columnIndex];
		return -1 < temp;
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

//// Time Limit Exceeded
//
// 
// /*
//	*Traversal all grids.
//	* When a grid value is not 0 (distance is not 0), start an expand search around current grid.
//	* Calculate resultand fill in result grid.
//	* /
// 
//#include <vector>
//#include <unordered_set>
//#include <queue>
//
//template <class T>
//inline void hash_combine(std::size_t& s, const T& v)
//{
//	std::hash<T> h;
//	s ^= h(v) + 0x9e3779b9 + (s << 6) + (s >> 2);
//}
//
//struct GridIndex
//{
//	size_t rowIndex;
//	size_t columnIndex;
//	GridIndex() : rowIndex(0), columnIndex(0) {}
//	GridIndex(size_t x, size_t y) : rowIndex(x), columnIndex(y) {}
//
//	inline bool operator==(const GridIndex& other) const
//	{
//		return this->rowIndex == other.rowIndex && this->columnIndex == other.columnIndex;
//	}
//};
//
//template <class T>
//class GridIndexHash;
//
//template<>
//struct GridIndexHash<GridIndex>
//{
//	size_t operator()(GridIndex const& g) const
//	{
//		size_t result = 0;
//		hash_combine(result, g.rowIndex);
//		hash_combine(result, g.columnIndex);
//		return result;
//	}
//};
//
//class Problem542
//{
//public:
//	std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
//	{
//		std::vector<std::vector<int>> result;
//		for (size_t i = 0, rowCount = mat.size(); i < rowCount; i++)
//		{
//			std::vector<int>& rowContent = mat[i];
//			std::vector<int> toAdd;
//			for (size_t j = 0, columnCount = rowContent.size(); j < columnCount; j++)
//			{
//				GridIndex currentGrid(i, j);
//				toAdd.push_back(calculateDistTo0Grid(mat, currentGrid));
//			}
//			result.push_back(toAdd);
//		}
//		return result;
//	}
//
//private:
//
//	int calculateDistTo0Grid(std::vector<std::vector<int>>& mat, GridIndex startGrid)
//	{
//		int currentGridValue = mat[startGrid.rowIndex][startGrid.columnIndex];
//		if (0 == currentGridValue)
//		{
//			return 0;
//		}
//
//		size_t rowCount = mat.size();
//		size_t columnCount = mat[0].size();
//		std::unordered_set<GridIndex, GridIndexHash<GridIndex>> visitedGridsSet;
//		std::queue<GridIndex> toVisit;
//		toVisit.push(startGrid);
//		GridIndex nearest0GridIndex = startGrid;
//		do
//		{
//			GridIndex gridToVisit = toVisit.front();
//			toVisit.pop();
//			size_t rowIndex = gridToVisit.rowIndex;
//			size_t columnIndex = gridToVisit.columnIndex;
//			std::vector<int>& rowContent = mat[rowIndex];
//			int gridContent = rowContent[columnIndex];
//			if (0 == gridContent)
//			{
//				nearest0GridIndex = gridToVisit;
//				break;
//			}
//
//			visitedGridsSet.insert(gridToVisit);
//			// visit 4 dir grids
//			if (0 < columnIndex) // vist left
//			{
//				GridIndex left(rowIndex, columnIndex - 1);
//				if (visitedGridsSet.find(left) == visitedGridsSet.end())
//				{
//					toVisit.push(left);
//				}
//			}
//			if (columnCount - 1 > columnIndex) // vist right
//			{
//				GridIndex right(rowIndex, columnIndex + 1);
//				if (visitedGridsSet.find(right) == visitedGridsSet.end())
//				{
//					toVisit.push(right);
//				}
//			}
//			if (0 < rowIndex) // visit up
//			{
//				GridIndex up(rowIndex - 1, columnIndex);
//				if (visitedGridsSet.find(up) == visitedGridsSet.end())
//				{
//					toVisit.push(up);
//				}
//			}
//			if (rowCount - 1 > rowIndex) // visit down
//			{
//				GridIndex down(rowIndex + 1, columnIndex);
//				if (visitedGridsSet.find(down) == visitedGridsSet.end())
//				{
//					toVisit.push(down);
//				}
//			}
//		} while (!toVisit.empty());
//
//		int result = nearest0GridIndex.rowIndex > startGrid.rowIndex ? nearest0GridIndex.rowIndex - startGrid.rowIndex : startGrid.rowIndex - nearest0GridIndex.rowIndex;
//		result += nearest0GridIndex.columnIndex > startGrid.columnIndex ? nearest0GridIndex.columnIndex - startGrid.columnIndex : startGrid.columnIndex - nearest0GridIndex.columnIndex;
//		return result;
//	}
//};