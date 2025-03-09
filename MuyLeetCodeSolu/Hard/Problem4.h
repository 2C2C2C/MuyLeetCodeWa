#pragma once

/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

Gather all num count.
Calculate mid num index (count / 2), mid num will be 1 or 2.
Do insert sorting until we meet the mis num index.
*/

#include <vector>

class Problem4
{
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::vector<int> mergeArray;
		bool isOneMedian = true;
		int pos = 0, nums1Length = nums1.size(), nums2Lenth = nums2.size();
		if (0!= nums1Length) // if nums1 is not empty
			pos += nums1.size();
		if (0!= nums2Lenth) // if nums2 is not empty
			pos += nums2.size();
		if (pos % 2 == 0) // 
			isOneMedian = false;
		pos /= 2;

		bool  mergeFinished = false;
		if (nums1Length == 0) // if nums1 is empty
		{
			mergeArray.insert(mergeArray.end(), nums2.begin(), nums2.end());
			mergeFinished = true;
		}
		else if (nums2Lenth == 0) // if nums2 is empty
		{
			mergeArray.insert(mergeArray.end(), nums1.begin(), nums1.end());
			mergeFinished = true;
		}

		int n1Index = 0, n2Index = 0, i = 0;
		// merge 2 array into 1 array
		while (i <= pos && !mergeFinished) // i <= pos cuz need to merge extra 1 element for calculation when there are 2 mid nums
		{
			if (n2Index >= nums2Lenth || (n1Index < nums1Length && nums1[n1Index] <= nums2[n2Index]))
				mergeArray.push_back(nums1[n1Index++]);
			else
				mergeArray.push_back(nums2[n2Index++]);
			i++;
		}
		if (isOneMedian) // get median
			return mergeArray[pos];
		else
			return ((double)(mergeArray[pos] + mergeArray[pos - 1])) / 2;
	}
};