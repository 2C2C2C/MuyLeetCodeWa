#pragma once

/*
80. Remove Duplicates from Sorted Array II
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/

/*
* iterate check array, also use a dup counter
* find dups(more than 2), shift array 1 element
*/

#include <vector>

class Problem80
{
public:
	static int removeDuplicates(std::vector<int>& nums)
	{
		unsigned length = nums.size();
		if (1 >= length)
		{
			return length;
		}

		unsigned deleteCount = 0;
		unsigned i = 0;
		int prevNum = nums[i++];
		short dupCount = 0;
		int temp;
		do
		{
			temp = nums[i];
			if (temp == prevNum)
			{
				++dupCount;
				if (dupCount > 1)
				{
					shiftToElement(nums, i);
					++deleteCount;
				}
				else
				{
					++i;
				}
				if (i >= length - deleteCount)
				{
					break;
				}
				continue;
			}
			dupCount = 0;
			prevNum = temp;
			++i;
		} while (i < length - deleteCount);


		if (0 < deleteCount)
		{
			nums.resize(length - deleteCount);
		}
		return length - deleteCount;
	}

private:

	static void shiftToElement(std::vector<int>& nums, unsigned index)
	{
		unsigned i = index, length = nums.size() - 1;
		while (i < length)
		{
			nums[i] = nums[i + 1]; // fix this
			++i;
		}
	}

};