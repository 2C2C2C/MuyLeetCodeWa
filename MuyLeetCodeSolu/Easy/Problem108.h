#pragma once

/*
108. Convert Sorted Array to Binary Search Tree
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/


#include <iostream>
#include <vector>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Problem108
{
public:
	static TreeNode* CreateTree(const std::vector<int>& num, int low, int high)
	{
		TreeNode *result = nullptr;
		if (low > high)
			return result;
		else
		{
			unsigned int mid = (low + high) >> 1;
			result = new TreeNode(num[mid]);
			result->left = CreateTree(num, low, mid - 1);
			result->right = CreateTree(num, mid + 1, high);
		}
		return result;
	}

	TreeNode* sortedArrayToBST(const std::vector<int>& nums)
	{
		TreeNode *root = nullptr;
		root = CreateTree(nums, 0, nums.size() - 1);

		return root;
	}
};