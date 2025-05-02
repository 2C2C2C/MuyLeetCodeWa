#pragma once

/*
139. Word Break
https://leetcode.com/problems/word-break/
*/

/* Need to use DP; DFS will timed out :(
* Create memo as with the same size as source string.
* Fill memo from 0 pos as 1st round. If any word can fit from start pos, fill memo[start pos + word length] to true.
* For next rounds, start from next pos where memo[index] is true.
* After fill memo, result is memo[sourceLength - 1]
*/

#include<string>
#include<vector>
//#include<stack>

class Problem139
{
public:
	bool wordBreak(std::string s, std::vector<std::string>& wordDict)
	{
		if (1 == wordDict.size())
		{
			return s == wordDict[0];
		}
		size_t sourceLength = s.size();
		std::vector<bool> memo(sourceLength, false);
		fillMemo(s, wordDict, memo);
		return memo[sourceLength - 1];
	}

private:
	void fillMemo(std::string& source, std::vector<std::string>& wordDict, std::vector<bool>& memo)
	{
		for (size_t i = 0, length = memo.size(); i < length; i++)
		{
			if (0 == i || memo[i - 1]) // if prev position can fill some words
			{
				for (size_t j = 0, wordCount = wordDict.size(); j < wordCount; j++)
				{
					std::string& word = wordDict[j];
					size_t wordLength = word.length();
					if (memo[i + wordLength - 1])
					{
						continue;
					}
					if (checkWordByChar(source, i, word))
					{
						memo[i + wordLength - 1] = true;
					}
				}
			}
		}
	}

	bool checkWordByChar(std::string& source, size_t startIndex, std::string& word)
	{
		size_t sourceLength = source.size();
		for (size_t i = 0, wordLength = word.size(); i < wordLength; i++)
		{
			if (startIndex > sourceLength - 1) // out of source 
			{
				return false;
			}
			if (source[startIndex + i] == word[i])
			{
				continue;
			}
			return false;
		}
		return true;
	}

	bool checkWordByHash(std::string& source, size_t startIndex, std::string& word) // try it with DFS but still time out :(
	{
		size_t sourceLength = source.size(), wordLength = word.size();
		if (sourceLength >= wordLength + startIndex)
		{
			size_t wordLength = word.size();
			std::string subSource = source.substr(startIndex, wordLength);
			size_t wordHash = std::hash<std::string>{}(word);
			size_t subSourceHash = std::hash<std::string>{}(subSource);
			return wordHash == subSourceHash;
		}
		return false;
	}


};