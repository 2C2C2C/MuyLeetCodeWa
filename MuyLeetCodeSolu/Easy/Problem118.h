#pragma once

/*
118. Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/
*/

#include <vector>

class Problem118
{
public:
	static std::vector<std::vector<int>> generate(int numRows)
	{
		std::vector<std::vector<int>> *result = new std::vector<std::vector<int>>();
		std::vector<int> *tempArr = nullptr;
		if (numRows <= 0)
			return *result;
		else
		{
			// for row 1
			tempArr = new std::vector<int>();
			tempArr->push_back(1);
			result->push_back(*tempArr);

			if (numRows > 1)
			{
				std::vector<int> prevArr;
				for (unsigned i = 1; i < numRows; i++)
				{
					tempArr = new std::vector<int>();
					prevArr = result->back();
					tempArr->push_back(1);
					for (unsigned j = 0; j < prevArr.size() - 1; j++)
						tempArr->push_back(prevArr[j] + prevArr[j + 1]);
					tempArr->push_back(1);
					result->push_back(*tempArr);
				}
			}
		}

		return *result;
	}
};