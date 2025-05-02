#pragma once

/*
334. Increasing Triplet Subsequence
https://leetcode.com/problems/increasing-triplet-subsequence
*/

/* Fixed slide window.
* Use 2 slide window.
* 1st window go find Triplet.
* 2nd used to check same pattern.
* 2nd window starts when 1st window find a element equals the left element of 1st window.
* If find same pattern, replace 1st start index with current 2nd window start index.
*/

#include<vector>

class Problem334
{
public:
	bool increasingTriplet(std::vector<int>& nums)
	{
		size_t  numCount = nums.size();
		if (3 > numCount) // edge cases
		{
			return false;
		}
		std::vector<int> window, subWindow;
		size_t left = 0, right = 1, subLeft = 0;
		window.push_back(nums[left]);
		do
		{
			int tempNum = nums[right];
			size_t windowSize = window.size();
			if (1 == windowSize)
			{
				if (tempNum <= window[0]) // next value is smaller than window head, swap head
				{
					window[0] = tempNum;
					left = right;
				}
				else
				{
					window.push_back(tempNum);
				}
				right++;
			}
			else
			{
				// window size > 1, check from right side
				if (tempNum > window[1])
				{
					window.push_back(tempNum);
				}
				else if (tempNum < window[1])
				{
					if (tempNum == window[0])
					{
						subWindow.clear();
						subWindow.push_back(tempNum);
						subLeft = right;
					}
					else if (tempNum > window[0])
					{
						window[1] = tempNum;
					}
				}
				else // tempNum == window[1]
				{
					if (1 == subWindow.size()) // find same pattern
					{
						left = subLeft;
						subWindow.clear();
					}
				}
				right++;
			}

			if (3 <= (windowSize = window.size()))
			{
				return true;
			}
			if (right < numCount)
			{
				continue;
			}
			// window right side reachs end, start a new window
			left = left + windowSize;
			if (left < numCount)
			{
				right = left + 1;
				window.clear();
				window.push_back(nums[left]);
			}
			else
			{
				break;
			}
		} while (right < numCount);
		return false;
	}

};