#pragma once

#include <iostream>
#include <vector>

class Problem283
{
public:
	static void moveZeroes(std::vector<int>& nums)
	{
		if (nums.size() < 2) return;
		int head = 0, back = nums.size() - 1;
		unsigned int i = 0;

		while (nums[back] == 0)
		{
			back--;
			if (back < 0) return;
		}

		while (i < back)
		{
			if (nums[i] == 0)
			{
				// neet to move to back
				head = i;
				do
				{
					std::swap(nums[head], nums[head + 1]);
					head++;
				} while (head != back);
				while (nums[back] == 0)
					back--;
			}
			if (nums[i] != 0)
				i++;
		}

		//// bubble sort like, too fking slow
		//for (unsigned int i = 0; i < nums.size(); i++)
		//{
		//	for (unsigned int j = 0; j < nums.size() - 1 - i; j++)
		//	{
		//		if (nums[j] == 0)
		//			std::swap(nums[j], nums[j + 1]);
		//	}
		//}
	}

};

