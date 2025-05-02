#pragma once

/*
931. Minimum Falling Path Sum
https://leetcode.com/problems/minimum-falling-path-sum
*/

/* Dynamic programming :(
* Separate problems into each grid.
* For each grid, min value is self plus the min(down-left,down,down-right). Stores this result into memo.
* Do fill memo for the top row, and the min value from top row is the result.
*/

#include<vector>

class Problem931
{
public:
	int minFallingPathSum(std::vector<std::vector<int>>& matrix)
	{
		if (matrix.empty()) // well, I think this edge case does not exist
		{
			return INT_MAX;
		}
		// init memo
		size_t rowCount = matrix.size();
		std::vector<int>& tempRow = matrix[0];
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
			int tempValue = dp(matrix, 0, i, memo, memoCheck);
			result = std::min(tempValue, result);
		}
		return result;
	}

private:
	int dp(std::vector<std::vector<int>>& matrix, size_t rowIndex, size_t columnIndex, std::vector<std::vector<int>>& memo, std::vector<std::vector<bool>>& memoCheck)
	{
		// check momo first
		int memoValue;
		if (isMemoValueInit(memoCheck, rowIndex, columnIndex))
		{
			memoValue = getMemoValue(memo, rowIndex, columnIndex);
		}
		else // memo value is empty, fill it
		{
			std::vector<int>& row = matrix[rowIndex];
			size_t rowCount = matrix.size();
			if (rowIndex == rowCount - 1) // reach bottom
			{
				int result = row[columnIndex];
				setMemoValue(memo, memoCheck, rowIndex, columnIndex, memoValue = result);
			}
			else
			{
				// calculate bottom-left, bottom, bottom-right value;
				int bottomLeft = (0 == columnIndex ? INT_MAX : dp(matrix, rowIndex + 1, columnIndex - 1, memo, memoCheck));
				int bottom = dp(matrix, rowIndex + 1, columnIndex, memo, memoCheck);
				size_t columnCount = row.size();
				int bottomRight = (columnCount - 1 == columnIndex ? INT_MAX : dp(matrix, rowIndex + 1, columnIndex + 1, memo, memoCheck));
				// then get the min value
				int min = std::min(bottomLeft, bottom);
				min = std::min(min, bottomRight);
				memoValue = min + row[columnIndex]; // memo value is self + calculate result
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