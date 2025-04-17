#pragma once

/*
167. Two Sum II - Input Array Is Sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

/*
* Check edge case first.
* Use left right pointer.
* Left to 0 index, right to length -1.
* If sum is smaller than target, left++ get a greater value.
* If sum is greater than target, right-- get a smaller value.
* Keep check until get the answer or left meet right(can not find answer).
*/

#include <vector>

class Problem167
{
public:
	std::vector<int> twoSum(std::vector<int>& numbers, int target)
	{
		std::vector<int> result;
		int inputSize = numbers.size();
		if (2 == inputSize) // edge case
		{
			if (numbers[0] + numbers[1] == target)
			{
				result.push_back(1);
				result.push_back(2);
			}
			else
			{
				result.push_back(-1);
				result.push_back(-1);
			}
			return result;
		}

		int left = 0, right = inputSize - 1;
		do
		{
			int temp = numbers[left] + numbers[right];
			if (temp == target)
			{
				result.push_back(left + 1);
				result.push_back(right + 1);
				return result;
			}

			if (temp > target)
			{
				right--;
			}
			else // temp < target
			{
				left++;
			}

		} while (left < right); // If 2 pointer meet, than it means we didnt find the answer :(
		
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}

};