#pragma once

/*
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/

/*
* split array into 2 side from middle.
* either left side or right side will be already sorted, do binary search from sorted part for target(if find target just return).
* do mid-split for another side, and redo prev step.
*/

#include <vector>

class Problem33
{
public:
	static int search(std::vector<int>& nums, int target)
	{
		unsigned listLength = nums.size();
		switch (listLength) // deal edge cases
		{
		case 0:
			return -1;
		case 1:
			return nums[0] == target ? 0 : -1;
		case 2:
			return nums[0] == target ? 0 : (nums[1] == target ? 1 : -1);
		default:
			break;
		}

		unsigned tempHead = 0, tempTail = listLength - 1;
		unsigned tempMid = tempHead + tempTail / 2;
		int headVal = nums[0];
		while (tempHead <= tempTail)
		{
			int tempValue = nums[tempMid];
			if (target == tempValue)
			{
				return tempMid;
			}

			if (tempValue > headVal) // left side is sorted
			{
				if (target >= nums[tempHead] && target <= nums[tempMid])
				{
					return binarySearch(nums, tempHead, tempMid, target);
				}
				tempHead = tempMid + 1;
			}
			else // right side sorted
			{
				if (target >= nums[tempMid] && target <= nums[tempTail])
				{
					return binarySearch(nums, tempMid, tempTail, target);
				}
				if (0 == tempMid)
				{
					return -1;
				}
				tempTail = tempMid - 1;
			}

			unsigned delta = tempTail - tempHead;
			switch (delta) // deal edge cases; if we keep divide a num by 2, will finally get 1 then to 0; e.g. 5->2->1->0 6->3->1->0
			{
			case 0:
				return nums[tempHead] == target ? tempHead : -1;
			case 1:
				return nums[tempHead] == target ? tempHead : (nums[tempTail] == target ? tempTail : -1);
			default:
				break;
			}

			headVal = nums[tempHead];
			tempMid = tempHead + (tempTail - tempHead) / 2;
		}

		return -1;
	}

	static int binarySearch(std::vector<int>& nums, unsigned head, unsigned tail, int target)
	{
		int i = head, j = tail;
		while (i <= j)
		{
			int mid = i + (j - i) / 2;
			if (nums[mid] < target)
			{
				i = mid + 1;
			}
			else if (nums[mid] > target)
			{
				j = mid - 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;
	}

};