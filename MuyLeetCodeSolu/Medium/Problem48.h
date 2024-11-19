#pragma once

/*
48. Rotate Image
https://leetcode.com/problems/rotate-image/
*/

/*
* Diagonal(up left to right down) flip the matrix.
* Revis every horizontal line.
*/

#include <iostream>
#include <vector>

class Problem48
{
public:
	static void rotate(std::vector<std::vector<int>>& matrix)
	{
		if (matrix.size() < 2) return;
		int matrixSize = matrix.size();

		// diagonal flip(up left to right down)
		unsigned int i = 0, j = 0;
		while (i < matrixSize - 1)
		{
			j = i + 1;
			while (j < matrixSize)
			{
				std::swap((matrix[matrixSize - i - 1])[j], (matrix[matrixSize - j - 1])[i]);
				j++;
			}
			i++;
		}

		// revers X axis
		i = 0;
		while (i < matrixSize / 2)
		{
			std::swap(matrix[i], matrix[matrixSize - i - 1]);
			i++;
		}

	}
};

/*

1,2,3
1,2,3
1,2,3

3,2,3
2,2,3
1,1,1

3,3,3
2,2,2
1,1,1


x,x,x,x,o
x,x,x,o,x
x,x,o,x,x
x,o,x,x,x
o,x,x,x,x

x,x,x,x,x,x
x,x,x,x,x,x
x,x,x,x,x,x
x,x,x,x,x,x
x,x,x,x,x,x
x,x,x,x,x,x

x,x,x,x,x,x,x
x,x,x,x,x,x,x
x,x,x,x,x,x,x
x,x,x,x,x,x,x
x,x,x,x,x,x,x
x,x,x,x,x,x,x
x,x,x,x,x,x,x

*/