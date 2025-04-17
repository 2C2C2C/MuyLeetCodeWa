#pragma once

/*
27. Remove Element
https://leetcode.com/problems/remove-element/
*/

/*
* Fast slow pointer.
* Set Fast to 0, slow to -1.
* Check the num pointed by fast, if need to remove, fast move to next;
* If it is not dup, slow move to next and assign this new value to the slow pointed position.
* Keep doing prev 2 steps until Fast move to end.
* Then we get the result array, length is slow + 1
*/

#include <vector>

class Problem27
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		int sourceCount = nums.size();
		if (1 > sourceCount)
		{
			return 0;
		}

		int fastIndex = 0, slowIndex = -1;
		do
		{
			if (nums[fastIndex] == val)
			{
				fastIndex++;
				continue;
			}
			nums[++slowIndex] = nums[fastIndex++];
		} while (fastIndex < sourceCount);
		return slowIndex + 1;
	}

	// this would waste memory
	//int removeElement(std::vector<int>& nums, int val)
	//{
	//	if (nums.size() <= 0)
	//		return 0;
	//	std::vector<int> result;
	//	int current = val;
	//	int length = 0;
	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		// remove this element
	//		if (nums[i] != val)
	//		{
	//			result.push_back(nums[i]);
	//			length++;
	//		}
	//	}
	//	nums = result;
	//	return length;
	//}


};