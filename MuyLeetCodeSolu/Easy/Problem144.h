#pragma once

/*
144. 二叉树的前序遍历
https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
*/

/*
*
*/

#include <vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Problem144 
{
public:
	std::vector<int> preorderTraversal(TreeNode* root)
	{
		std::vector<int> result;
		traverse(root, result);
		return result;
	}

private:

	void traverse(TreeNode* node, std::vector<int>& result)
	{
		if (nullptr == node)
		{
			return;
		}
		result.push_back(node->val);

		traverse(node->left, result);

		traverse(node->right, result);

	}
};