#pragma once

/*
133. Clone Graph
https://leetcode.com/problems/clone-graph/description/
*/

/*
* Traversal the given graph(use DFS) and create the clone.
* Use a dictionary to store the visited nodes(as keys), and the nodes we clones (as values).
* When we traversaling to a visited node, get the clone from dictionaray and connect it.
*/

#include <vector>
#include <unordered_map>

class Node
{
public:
	int val;
	std::vector<Node*> neighbors;
	Node()
	{
		val = 0;
		neighbors = std::vector<Node*>();
	}
	Node(int _val)
	{
		val = _val;
		neighbors = std::vector<Node*>();
	}
	Node(int _val, std::vector<Node*> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

class Problem133
{
public:
	Node* cloneGraph(Node* node)
	{
		if (nullptr == node)
		{
			return nullptr;
		}

		std::unordered_map<Node*, Node*> nodeCache;
		Node* result = TraversalClone(node, nodeCache);
		return result;
	}

private:

	Node* TraversalClone(Node* source, std::unordered_map<Node*, Node*>& nodeCache)
	{
		Node* clone = new Node(source->val);
		nodeCache[source] = clone;
		std::vector<Node*>& sourceNeighbors = source->neighbors;
		for (size_t i = 0, length = sourceNeighbors.size(); i < length; i++)
		{
			Node& temp = *sourceNeighbors[i];
			if (nodeCache.find(&temp) == nodeCache.end()) // this node has not been visited
			{
				Node& clonedNeighbor = *TraversalClone(&temp, nodeCache);
				clone->neighbors.push_back(&clonedNeighbor);
			}
			else // node is already visited, get it from cache
			{
				clone->neighbors.push_back(nodeCache.at(&temp));
			}
		}
		return clone;
	}

};