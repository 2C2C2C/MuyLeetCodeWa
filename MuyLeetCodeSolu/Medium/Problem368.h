//#pragma once
//
///*
//368. Largest Divisible Subset
//https://leetcode.com/problems/largest-divisible-subset
//*/
//
///* it's DP.
//* Fill memo first (check and fill for every index).
//*/
//
//#include<vector>
//
//struct MemoData
//{
//	size_t nextIndex;
//	int result; // -1 means invalid
//	MemoData(size_t next, int r) : nextIndex(next), result(r) {}
//};
//
//class Problem368
//{
//public:
//	std::vector<int> largestDivisibleSubset(std::vector<int>& nums)
//	{
//		size_t numCount = nums.size();
//		std::vector<int> result;
//		switch (numCount)
//		{
//		case 0: result = nums;
//			break;
//		case 1: result = nums;
//			break;
//		default:
//			// fill memo
//			std::vector<MemoData> memo(numCount, MemoData(0, -1));
//			for (size_t i = 0; i < numCount; i++)
//			{
//				if (-1 == memo[i].result)
//				{
//					int baseValue = nums[i];
//					FillMemo(nums, i, baseValue, memo);
//				}
//			}
//			int count = -1;
//			size_t memoIndex = 0;
//			for (size_t i = 0, memoLength = memo.size(); i < memoLength; i++)
//			{
//				int temp = memo[i].result;
//				if (temp > count)
//				{
//					memoIndex = i;
//					count = temp;
//				}
//			}
//
//			// fill result
//			do
//			{
//				result.push_back(nums[memoIndex]);
//				MemoData& memoData = memo[memoIndex];
//				if (memoData.nextIndex == memoIndex)
//				{
//					break;
//				}
//				memoIndex = memoData.nextIndex;
//			} while (memoIndex < numCount);
//			break;
//		}
//		return result;
//	}
//
//private:
//	int FillMemo(std::vector<int>& nums, size_t currentIndex, int baseValue, std::vector<MemoData>& memo)
//	{
//		if (-1 == memo[currentIndex].result) // need to fill memo data
//		{
//			int currentNum = nums[currentIndex];
//			MemoData tempData(currentIndex, 1);
//			for (size_t i = currentIndex + 1, numCount = nums.size(); i < numCount; i++)
//			{
//				if (currentNum < nums[i] && 0 == nums[i] % currentNum)
//				{
//					int tempResult = 1 + FillMemo(nums, i, memo);
//					if (tempResult > tempData.result)
//					{
//						tempData.result = tempResult;
//						tempData.nextIndex = i;
//					}
//				}
//			}
//			return (memo[currentIndex] = tempData).result;
//		}
//		return memo[currentIndex].result;
//	}
//
//};