#pragma once

/*
543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/description/
*/

/*
* Define a func to calculate the depth for a node(left depth + right depth).
* Traverse the tree(I use BFS, but leetcode said it slow as fked :(, so sad), and calculate depth for every node.
* Pick the max value.
*/

#include<queue>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Problem543
{
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		if (nullptr == root || (nullptr == root->left && nullptr == root->right))
		{
			return 0;
		}

		int result = 0;
		std::queue<TreeNode*> queue;
		queue.push(root);
		// do a BFS for tree nodes, calculate deepth by using DFS for a node
		do
		{
			TreeNode* node = queue.front();
			queue.pop();
			int temp = SumChildTreeDepth(node);
			if (temp > result)
			{
				result = temp;
			}
			if (nullptr != node->left)
			{
				queue.push(node->left);
			}
			if (nullptr != node->right)
			{
				queue.push(node->right);
			}
		} while (!queue.empty());
		return result;
	}

private:
	int SumChildTreeDepth(TreeNode* root)
	{
		int leftDepth = nullptr == root->left ? 0 : CalculateMaxTreeDepth(root->left, 0);
		int rightDepth = nullptr == root->right ? 0 : CalculateMaxTreeDepth(root->right, 0);
		return leftDepth + rightDepth;
	}

	int CalculateMaxTreeDepth(TreeNode* currentNode, int prevNodeDeep)
	{
		int currentDepth = prevNodeDeep + 1;
		// traversal left child
		int leftDepth = nullptr == currentNode->left ? currentDepth : CalculateMaxTreeDepth(currentNode->left, currentDepth);
		// traversal right child
		int rightDepth = nullptr == currentNode->right ? currentDepth : CalculateMaxTreeDepth(currentNode->right, currentDepth);
		return leftDepth > rightDepth ? leftDepth : rightDepth;
	}
};