#pragma once

/*
1289. Minimum Falling Path Sum II
https://leetcode.com/problems/minimum-falling-path-sum-ii
*/

/* Dynamic programming :(
* Separate problems into each grid.
* For each grid, min value is self plus the min(look through next row, do not select down element). Stores this result into memo.
* Do fill memo for the top row, and the min value from top row is the result.
*/

#include<vector>

class Problem1289
{
public:
	int minFallingPathSum(std::vector<std::vector<int>>& grid)
	{
		if (grid.empty()) // well, I think this edge case does not exist
		{
			return INT_MAX;
		}
		// init memo
		size_t rowCount = grid.size();
		std::vector<int>& tempRow = grid[0];
		if (tempRow.empty()) // well, I think this edge case does not exist
		{
			return INT_MAX;
		}
		size_t columnCount = tempRow.size();
		std::vector<std::vector<int>> memo(rowCount, std::vector<int>(columnCount, -1));
		std::vector<std::vector<bool>> memoCheck(rowCount, std::vector<bool>(columnCount, false));
		int result = INT_MAX;
		for (size_t i = 0; i < columnCount; i++)
		{
			int tempValue = dp(grid, 0, i, memo, memoCheck);
			result = std::min(tempValue, result);
		}
		return result;
	}

private:
	int dp(std::vector<std::vector<int>>& grid, size_t rowIndex, size_t columnIndex, std::vector<std::vector<int>>& memo, std::vector<std::vector<bool>>& memoCheck)
	{
		// check momo first
		int memoValue = INT_MAX;
		if (isMemoValueInit(memoCheck, rowIndex, columnIndex))
		{
			memoValue = getMemoValue(memo, rowIndex, columnIndex);
		}
		else // memo value is empty, fill it
		{
			std::vector<int>& row = grid[rowIndex];
			size_t rowCount = grid.size();
			if (rowIndex == rowCount - 1) // reach bottom
			{
				int result = row[columnIndex];
				setMemoValue(memo, memoCheck, rowIndex, columnIndex, memoValue = result);
			}
			else
			{
				size_t columnCount = row.size();
				for (size_t i = 0; i < columnCount; i++)
				{
					if (i == columnIndex)
					{
						continue;
					}
					int temp = dp(grid, rowIndex + 1, i, memo, memoCheck);
					memoValue = std::min(temp, memoValue);
				}
				memoValue += row[columnIndex]; // memo value is self + calculate result
				setMemoValue(memo, memoCheck, rowIndex, columnIndex, memoValue);
			}
		}
		return memoValue;
	}

	int getMemoValue(std::vector<std::vector<int>>& memo, size_t rowIndex, size_t columnIndex)
	{
		std::vector<int>& memoRow = memo[rowIndex];
		int value = memoRow[columnIndex];
		return value;
	}

	void setMemoValue(std::vector<std::vector<int>>& memo, std::vector<std::vector<bool>>& memoCheck, size_t rowIndex, size_t columnIndex, int value)
	{
		std::vector<int>& memoRow = memo[rowIndex];
		memoRow[columnIndex] = value;

		std::vector<bool>& memoCheckRow = memoCheck[rowIndex];
		memoCheckRow[columnIndex] = true;
	}

	bool isMemoValueInit(std::vector<std::vector<bool>>& memoCheck, size_t rowIndex, size_t columnIndex)
	{
		std::vector<bool>& memoRow = memoCheck[rowIndex];
		bool result = memoRow[columnIndex];
		return result;
	}
};

/* Dynamic programming (simplified)
* Goes from top row to bottom row.
* Use a array(length = column count) to cache calculate result for each row.
* Start for row 1 (the row under the top row). For each num in row, the new cache result is current value plus the valid min value from prev cache result.
* Traverse rest rows by prev step, and the final result is the min value from cache data.
*/

class Problem1289_ext1
{
public:
	int minFallingPathSum(std::vector<std::vector<int>>& grid)
	{
		if (grid.empty()) // well, I think this edge case does not exist
		{
			return INT_MAX;
		}
		std::vector<int>& topRow = grid[0];
		if (topRow.empty()) // well, I think this edge case does not exist
		{
			return INT_MAX;
		}

		// get create cache
		std::vector<int>prevSumCache = topRow;
		std::vector<int>currentSumCache = topRow;
		size_t rowCount = grid.size();
		size_t columnCount = topRow.size();
		// get min1 and min2
		size_t min1 = 0, min2 = 0;
		getMin1AndMin2(prevSumCache, min1, min2); // get the 1st and 2nd min index from cache data
		// go down each row
		for (size_t i = 1; i < rowCount; i++)
		{
			std::vector<int>& tempRow = grid[i];
			// fill cache
			for (size_t j = 0; j < columnCount; j++)
			{
				int temp = min1 == j ? prevSumCache[min2] : prevSumCache[min1]; // check index and add num
				currentSumCache[j] = temp + tempRow[j];
			}
			for (size_t j = 0; j < columnCount; j++)
			{
				prevSumCache[j] = currentSumCache[j];
			}
			getMin1AndMin2(prevSumCache, min1, min2); // get the 1st and 2nd min index from cache data
		}

		int result = prevSumCache[0];
		for (size_t i = 1; i < columnCount; i++)
		{
			result = std::min(prevSumCache[i], result);
		}
		return result;
	}

private:
	void getMin1AndMin2(std::vector<int>& grid, size_t& min1, size_t& min2)
	{
		min1 = min2 = 0;
		int min1Value = grid[0], min2Value = INT_MAX;
		for (size_t i = 1, length = grid.size(); i < length; i++)
		{
			int tempValue = grid[i];
			if (tempValue < min1Value)
			{
				min2Value = min1Value;
				min1Value = tempValue;
				min2 = min1;
				min1 = i;
			}
			else if (tempValue < min2Value)
			{
				min2Value = tempValue;
				min2 = i;
			}
		}
	}
};