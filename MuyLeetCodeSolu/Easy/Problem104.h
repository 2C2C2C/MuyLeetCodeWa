#pragma once

/*
104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

/*
*
*/

#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Problem104
{
public:
	int maxDepth(TreeNode* root)
	{
		return maxDepthSolu2(root);
	}

private:

	// solution 1
	int maxDepthSolu1(TreeNode* root)
	{
		if (nullptr == root)
		{
			return 0;
		}

		int leftSum = maxDepthSolu1(root->left);
		int rightSum = maxDepthSolu1(root->right);
		return 1 + std::max(leftSum, rightSum);
	}

	// solution 2
	int maxDepthSolu2(TreeNode* root)
	{
		if (nullptr == root)
		{
			return 0;
		}

		int result = 0;
		int currentDepth = 0;

		TraverseNodes(root, currentDepth, result);
		return result;
	}

	void TraverseNodes(TreeNode* node, int& depth, int& result)
	{
		if (node == nullptr)
		{
			return;
		}
		depth = depth + 1;
		if (nullptr == node->left && nullptr == node->right) // reach leave node
		{
			if (depth > result)
			{
				result = depth;
			}
		}
		TraverseNodes(node->left, depth, result);
		TraverseNodes(node->right, depth, result);
		depth = depth - 1;
	}

};