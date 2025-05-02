#pragma once

/*
112. Path Sum
https://leetcode.com/problems/path-sum
*/

/*
*
*
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Problem112
{
public:
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		return Check(root, targetSum);
	}

private:
	bool Check(TreeNode* root, int targetSum)
	{
		if (nullptr == root)
		{
			return false;
		}
		int currentNodeValue = root->val;
		if (targetSum == currentNodeValue && nullptr == root->left && nullptr == root->right)
		{
			return true;
		}
		int subTarget = targetSum - currentNodeValue;
		return Check(root->left, subTarget) || Check(root->right, subTarget);
	}
};