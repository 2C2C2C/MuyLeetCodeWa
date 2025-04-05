#pragma once

/*
36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/description/
*/

/*
* go check every grid
* check grid by row, column and current box(3*3)
* record the number exist times in row, column and box
* go through all grids, if a num exist more than once, return false
*/

#include <vector>

class Problem36
{
public:
	// inner vector is row
	static bool isValidSudoku(std::vector<std::vector<char>>& board)
	{
		bool rowNumExist[9][10] = { 0 };
		bool columnNumExist[9][10] = { 0 };
		bool boxNumExist[9][10] = { 0 };

		for (size_t i = 0, columnCount = board.size(); i < columnCount; i++)
		{
			std::vector<char>& row = board[i];
			for (size_t j = 0, rowNumCount = row.size(); j < rowNumCount; j++)
			{
				char tempChar = row[j];
				if (tempChar == '.') // empty slot
				{
					continue;
				}
				int tempNum = tempChar - '0';

				// check row
				int existTimes = rowNumExist[i][tempNum];
				if (1 > existTimes)
				{
					rowNumExist[i][tempNum] = existTimes + 1;
				}
				else
				{
					return false;
				}

				// check column
				existTimes = columnNumExist[j][tempNum];
				if (1 > existTimes)
				{
					columnNumExist[j][tempNum] = existTimes + 1;
				}
				else
				{
					return false;
				}

				// check box
				// i / 3; 0 top; 1 mid; 2 bottom;
				// j / 3; 0 left; 1 mid; 2 right;
				int boxIndex = ((i / 3) * 3) + j / 3;
				existTimes = boxNumExist[boxIndex][tempNum];
				if (1 > existTimes)
				{
					boxNumExist[boxIndex][tempNum] = existTimes + 1;
				}
				else
				{
					return false;
				}
			}
		}

		return true;
	}
};