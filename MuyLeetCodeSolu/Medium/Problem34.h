#pragma once


/*
34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <vector>

class Problem34
{
public:
	static std::vector<int> searchRange(std::vector<int>& nums, int target)
	{
		std::vector<int> result;
		if (nums.size() < 1)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		else if (nums.size() == 1)
		{
			int temp = 0;
			if (nums[0] != target)
				temp = -1;
			result.push_back(temp);
			result.push_back(temp);
			return result;
		}

		int mid = 0, low = 0, high = 0;

		low = 0, high = nums.size() - 1;
		mid = (high - low) / 2;
		while (true) // to find the first
		{
			if (nums[mid] < target && nums[mid + 1] == target)
			{
				mid++;
				result.push_back(mid);
				break;
			}
			else if (low == mid || high == mid)
			{
				if (nums[mid] != target)
				{
					result.push_back(-1);
					result.push_back(-1);
					return result;
				}
				else if (nums[mid] == target)
				{
					result.push_back(mid);
					break;
				}
			}
			else
			{
				if (nums[mid] >= target)
				{
					high = mid;
					mid = low + (high - low) / 2;
				}
				else
				{
					low = mid;
					mid = low + (high - low) / 2;
				}
			}
		}

		if (mid + 1 == nums.size() || nums[mid] < nums[mid + 1])
		{
			result.push_back(mid);
			return result;
		}

		low = result[0] + 1;
		high = nums.size() - 1;
		mid = low + (high - low) / 2;
		while (true) // to find the second
		{
			if (nums[mid - 1] == target && nums[mid] > target)
			{
				mid--;
				result.push_back(mid);
				break;
			}
			else if (mid == high)
			{
				result.push_back(mid);
				break;
			}
			else
			{
				if (nums[mid] == target)
				{
					low = mid + 1;
					mid = low + (high - low) / 2;
				}
				else
				{
					high = mid;
					mid = low + (high - low) / 2;
				}
			}
		}

		return result;
	}
};
