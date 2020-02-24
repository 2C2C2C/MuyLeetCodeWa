#pragma once

/*
88. Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array
*/

#include <vector>

class Problem88
{
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		int i = 0, j = 0;
		nums1.resize(m);
		std::vector<int>::iterator it = nums1.begin();
		for (i = 0; i < nums2.size(); i++)
		{
			while (j <= m)
			{
				if (j == m)
				{
					while (i < nums2.size())
					{
						nums1.push_back(nums2[i++]);
					}
					return;
				}
				else if (nums2[i] <= nums1[j])
				{
					// can insert
					nums1.insert(it, nums2[i]);
					it = nums1.begin();
					m++;
					for (int k = 0; k < j; k++)
						it++;
					break;
				}
				else
				{
					it++;
					j++;
				}
			}
		}
	}
};