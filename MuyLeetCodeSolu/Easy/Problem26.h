#pragma once

/*
26. Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

/* 
* Fast slow pointer.
* Set Slow to the 0 index, Fast to the 1. And the num to be check if dupilicated is pointed by slow.
* Check the num pointed by fast, if dup, fast move to next;
* If it is not dup, slow move to next and assign this new value to the slow pointed position.
* Keep doing prev 2 steps until Fast move to end.
* Then we get the result array, length is slow + 1
*/

#include <vector>

class Problem26
{
public:
	int removeDuplicates(std::vector<int>& nums)
	{
		size_t sourceSize = nums.size();
		switch (sourceSize)
		{
			case 0:return 0;
			case 1:return 1;
			default:break;
		}
		int fastIndex = 1, slowIndex = 0;
		int dupNum = nums[0];
		do
		{
			if (nums[fastIndex] == dupNum) // num is dup, check next
			{
				fastIndex++;
				continue;
			}

			// num is not dup
			dupNum = nums[++slowIndex] = nums[fastIndex];
			fastIndex++;
		} while (fastIndex < sourceSize);

		return slowIndex + 1;
	}

	// this would use too much memory
	//static int removeDuplicates(std::vector<int>& nums)
	//{
	//	std::vector<int> result;
	//	if (nums.size() <= 0)
	//		return 0;
	//	// push first element
	//	int current = nums[0];
	//	result.push_back(current);

	//	int length = 1;
	//	for (int i = 1; i < nums.size(); i++)
	//	{
	//		// check if repeat
	//		if (current != nums[i])
	//		{
	//			length++;
	//			current = nums[i];
	//			result.push_back(current);
	//		}
	//	}
	//	nums = result;
	//	return length;
	//}

};