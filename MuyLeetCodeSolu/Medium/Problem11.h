#pragma once

/*
11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/
*/

#include <iostream>
#include <vector>

class Problem11
{
public:
	static int maxArea(std::vector<int>& height)
	{
		int result = 0, tempResult = 0;
		int left = 0, right = height.size() - 1;

		while (true)
		{
			if (left == right)
				break;
			else
			{
				tempResult = (right - left) * fmin(height[left], height[right]);
				if (tempResult > result)
					result = tempResult;
				
				// TODO : understand why move like this
				if (height[left] >= height[right])
					right--;
				else
					left++;
			}
		}

		return result;
	}
};