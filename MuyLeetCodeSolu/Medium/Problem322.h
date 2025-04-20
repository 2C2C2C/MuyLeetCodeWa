#pragma once

/*
322. Coin Change
https://leetcode.com/problems/coin-change
*/

/*
* Dynamic programming.
* Separate require into different pieces.
* Find the best answer for those pieces and store then into a dictionary or some other container.
* Get pieces answers by traverse the input coins.
*/

#include<vector>

class Problem322
{
public:
	int coinChange(std::vector<int>& coins, int amount)
	{
		// need amount + 1 grid, cuz we would have 0 ~ amount sub result
		// -2 means uninitialized
		std::vector<int> memo((size_t)amount + 1, -2);
		int result = dp(coins, amount, memo);
		return result;
	}

private:
	int dp(std::vector<int>& coins, int require, std::vector<int>& memo)
	{
		if (0 == require)
		{
			return 0;
		}
		if (0 > require)
		{
			return -1; // -1 means invalid case, can not find answer
		}

		if (-2 == memo[require]) // -2 means uninitialized
		{
			int result = INT_MAX;
			for (size_t i = 0, coinCount = coins.size(); i < coinCount; i++) // foreach coint to try different answer
			{
				int currentCoinValue = coins[i];
				int subResult = dp(coins, require - currentCoinValue, memo);
				if (-1 == subResult)
				{
					continue; // current coin value cant find answer, try next one
				}
				result = std::min(result, subResult + 1); // + 1 means add self coin to create this answer :)
			}
			memo[require] = (result == INT_MAX) ? -1 : result; // -1 means invalid case, can not find answer
		}
		return memo[require];
	}
};