#pragma once

/*
121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/s
*/

#include <vector>

class Problem121s
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int minPrice = INT32_MAX;
		int maxProfit = 0;
		int tempProfit = 0;
		for (unsigned i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minPrice)
				minPrice = prices[i];
			// calculate profit
			tempProfit = prices[i] - minPrice;
			if (tempProfit > maxProfit)
				maxProfit = tempProfit;
		}
		return maxProfit;
	}
};