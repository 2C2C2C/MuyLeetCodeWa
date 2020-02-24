#pragma once

/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/
*/

#include <vector>

class Solution
{
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::vector<int> tmpWa;
		bool isOneMedian = true, finish = false;
		int pos = 0, n1 = 0, n2 = 0, i = 0;
		if (nums1.size())
			pos += nums1.size();
		if (nums2.size())
			pos += nums2.size();
		if (pos % 2 == 0) // 
			isOneMedian = false;
		pos /= 2;

		if (nums1.size() == 0)
		{
			tmpWa.insert(tmpWa.end(), nums2.begin(), nums2.end());
			finish = true;
		}
		else if (nums2.size() == 0)
		{
			tmpWa.insert(tmpWa.end(), nums1.begin(), nums1.end());
			finish = true;
		}

		// combine 2 array into 1 array
		while (i <= pos && !finish)
		{
			if (n2 >= nums2.size() || (n1 < nums1.size() && nums1[n1] <= nums2[n2]))
				tmpWa.push_back(nums1[n1++]);
			else
				tmpWa.push_back(nums2[n2++]);
			i++;
		}
		if (isOneMedian) // get median
			return tmpWa[pos];
		else
			return ((double)(tmpWa[pos] + tmpWa[pos - 1])) / 2;
	}
};