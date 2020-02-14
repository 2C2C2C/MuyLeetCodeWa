#pragma once

/*
122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

#include <vector>

class Problem122
{
public:
	static int maxProfit(std::vector<int>& prices)
	{
		int maxProfit = 0;
		for (unsigned int i = 1; i < prices.size(); i++)
		{
			if (prices[i - 1] < prices[i])
				maxProfit += prices[i] - prices[i - 1];
		}
		return maxProfit;
	}
};