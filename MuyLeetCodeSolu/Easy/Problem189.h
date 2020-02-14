#pragma once

/*
189. Rotate Array
https://leetcode.com/problems/rotate-array/
*/

#include <vector>

class Problem189
{
public:

	static void rotate(std::vector<int>& nums, int k)
	{
		std::vector<int> temp = nums;
		k = nums.size() - k % nums.size(); // for rotate

		for (unsigned int i = 0; i < nums.size(); i++)
			nums[i] = temp[(i + k) % nums.size()];

	}

	//// circle repalce , not finished
	//static void rotate2(std::vector<int>& nums, int k)
	//{
	//	std::vector<int> temp = nums;
	//	k = k % nums.size(); // for rotate

	//	int prevVal = 0;
	//	int currentIndex = 0, nextIndex = 0;

	//	nextIndex = (currentIndex + k) % nums.size();
	//	prevVal = nums[currentIndex];
	//	do
	//	{
	//		nextIndex = (currentIndex + k) % nums.size();
	//		std::swap(prevVal, nums[nextIndex]);
	//		currentIndex = nextIndex;
	//	} while (currentIndex != 0);

}
};