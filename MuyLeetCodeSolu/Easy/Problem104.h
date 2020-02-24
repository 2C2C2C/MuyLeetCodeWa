#pragma once

/*
101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/
*/

#include <iostream>
#include <stack>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool CompareTreeNode(TreeNode* t1, TreeNode* t2)
	{
		if (t1 == NULL)
		{
			if (t2 == NULL)
				return true;
			else
				return false;
		}
		else if (t2 != NULL)
			return (t1->val == t2->val);
		else
			return false;
	}

	bool isSymmetric(TreeNode* root)
	{
		if (root == NULL)
			return true;
		//
		std::stack<TreeNode*> leftTreeStack;
		std::stack<TreeNode*> rightTreeStack;

		TreeNode *leftTree = root->left;
		TreeNode *rightTree = root->right;

		bool finish = false;
		bool result = true;
		result = result && CompareTreeNode(leftTree, rightTree);
		if (!result)
			return false;
		while (!finish)
		{
			while (leftTree != NULL || !leftTreeStack.empty())
			{
				while (leftTree != NULL)
				{

					// compare value here
					result = result && CompareTreeNode(leftTree, rightTree);
					if (!result)
						return false;

					// get more
					leftTreeStack.push(leftTree);
					leftTree = leftTree->left;

					rightTreeStack.push(rightTree);
					rightTree = rightTree->right;
				}
				if (rightTree != NULL)
					return false;

				// other
				if (!leftTreeStack.empty() && !rightTreeStack.empty())
				{
					// left
					leftTree = leftTreeStack.top();
					leftTreeStack.pop();
					leftTree = leftTree->right;
					// right
					rightTree = rightTreeStack.top();
					rightTreeStack.pop();
					rightTree = rightTree->left;
				}
				else
				{
					// maybe some error
					finish = true;
					result = false;
				}
			}
			finish = true;
			if (rightTree != NULL || !rightTreeStack.empty())
				result = false;
		}

		return result;
	}

};