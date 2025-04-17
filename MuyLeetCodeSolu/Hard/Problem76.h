#pragma once

/*
76. Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/
*/

/*
* Use a slide window.
* Use 2 bucket. 1 bucket for record the requirements of char and count, another 1 for record char usage for window.
* Window start from index 0.
*/

#include <string>
#include <vector>

class Problem76
{
public:
	std::string minWindow(std::string s, std::string t)
	{
		// edge case
		size_t sourceLength = s.length();
		size_t checkLength = t.length();
		int charCapA = 'A';
		switch (sourceLength)
		{
		case 0:
			return "";
		case 1:
			if (t.length() > sourceLength)
			{
				return "";
			}
			if (s[0] == t[0])
			{
				return s;
			}
			return "";
			break;
		default:
			if (checkLength > sourceLength)
			{
				return "";
			}
			break;
		}

		size_t left = 0, right = 0;
		size_t resultLeft, resultRight;
		size_t currentLength = 0;

		// Create bucket. No need to use map, bucket is easy to use.
		std::vector<size_t> checkBucket;
		std::vector<size_t> windowbucket;
		/* HACK @Hiko
		* 64 is enought from 'A' to 'z'.This would waste some space for char like '[', ']' but it's just ok :)
		* https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
		*/
		for (int i = 0; i < 64; i++)
		{
			checkBucket.push_back(0);
			windowbucket.push_back(0);
		}
		for (size_t i = 0; i < checkLength; i++)
		{
			char temp = t[i];
			int tempIndex = temp - charCapA;
			size_t tempCount = 1 + checkBucket[tempIndex];
			checkBucket[tempIndex] = tempCount;
		}

		int headChar = s[0] - charCapA;
		windowbucket[headChar] = 1;
		do
		{
			if (isInputMeetRequirement(windowbucket, checkBucket))
			{
				size_t tempLength = right - left + 1;
				if (0 == currentLength || tempLength < currentLength)
				{
					resultLeft = left;
					resultRight = right;
					currentLength = tempLength;
				}

				left++; // shrink window, since we already get a answer we need to find a better one
				if (1 <= left) // Tweak window bucket
				{
					int removeChar = s[left - 1] - charCapA;
					size_t removeCharCount = windowbucket[removeChar] - 1;
					windowbucket[removeChar] = removeCharCount;
				}
			}
			else
			{
				right++; // expand window to get more chars
				if (right < sourceLength) // Tweak window bucket
				{
					int addChar = s[right] - charCapA;
					size_t addCharCount = windowbucket[addChar] + 1;
					windowbucket[addChar] = addCharCount;
				}
			}
		} while (right < sourceLength);

		if (0 == currentLength)
		{
			return "";
		}

		return s.substr(resultLeft, currentLength);
	}

private:
	bool isInputMeetRequirement(std::vector<size_t>& input, std::vector<size_t>& check)
	{
		for (size_t i = 0, length = check.size(); i < length; i++)
		{
			if (0 == check[i] || input[i] >= check[i]) // contains enough char from check
			{
				continue;
			}
			return false;
		}
		return true;
	}
};