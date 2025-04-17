#pragma once

/*
438. Find All Anagrams in a String
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

/*
* Use fixed size slide window to stores temp sub string.
* Use bucket to store char usage for check string and temp sub string.
* Keep moving window to right and use 2 bucked to compare char usage.
* Find answe, push into result.
*/

#include <string>
#include <vector>

class Problem438 
{
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        std::string input = s;
        std::string check = p;
        std::vector<int> result;

        size_t checkLength = check.length();
        size_t inputLength = input.length();

        // edge case
        if (checkLength > inputLength)
        {
            return result;
        }

		int charCapA = 'A';
		size_t left = 0, right = 0;

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
			char temp = check[i];
			int tempIndex = temp - charCapA;
			size_t tempCount = 1 + checkBucket[tempIndex];
			checkBucket[tempIndex] = tempCount;
		}

		int headChar = input[0] - charCapA;
		windowbucket[headChar] = 1;
		do
		{
			size_t windowWidth = right - left + 1;
			if (windowWidth < checkLength)
			{
				right++;
				if (right < inputLength) // Tweak window bucket
				{
					int addChar = input[right] - charCapA;
					size_t addCharCount = windowbucket[addChar] + 1;
					windowbucket[addChar] = addCharCount;
				}
			}
			else if (windowWidth > checkLength)
			{
				left++;
				if (1 <= left) // Tweak window bucket
				{
					int removeChar = input[left - 1] - charCapA;
					size_t removeCharCount = windowbucket[removeChar] - 1;
					windowbucket[removeChar] = removeCharCount;
				}
			}
			else
			{
				if (isInputMeetRequirement(windowbucket, checkBucket))
				{
					result.push_back((int)left);
				}

				// slide window move right

				left++; // shrink window, since we already get a answer we need to find a better one
				if (1 <= left) // Tweak window bucket
				{
					int removeChar = input[left - 1] - charCapA;
					size_t removeCharCount = windowbucket[removeChar] - 1;
					windowbucket[removeChar] = removeCharCount;
				}

				right++; // expand window to get more chars
				if (right < inputLength) // Tweak window bucket
				{
					int addChar = input[right] - charCapA;
					size_t addCharCount = windowbucket[addChar] + 1;
					windowbucket[addChar] = addCharCount;
				}
			}
		} while (right < inputLength);

        return result;
    }

private:
	bool isInputMeetRequirement(std::vector<size_t>& input, std::vector<size_t>& check)
	{
		for (size_t i = 0, length = check.size(); i < length; i++)
		{
			if (check[i] == input[i]) // contains enough char from check
			{
				continue;
			}
			return false;
		}
		return true;
	}
};