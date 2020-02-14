#pragma once

/*
155. Min Stack
https://leetcode.com/problems/min-stack/
*/

#include <iostream>

class MinStack
{
public:
	struct StackNode
	{
		int m_val;
		StackNode* m_prev;
		StackNode(int val) : m_val(val), m_prev(NULL) {}
	};

	MinStack()
	{
		m_stackTop = m_minLinkTop = nullptr;
	}

	~MinStack()
	{
		StackNode* tempNode = nullptr;

		// delete stack
		while (nullptr != m_stackTop)
		{
			tempNode = m_stackTop->m_prev;
			delete m_stackTop;
			m_stackTop = tempNode;
		}

		// delete min list
		while (nullptr != m_minLinkTop)
		{
			tempNode = m_minLinkTop->m_prev;
			delete m_minLinkTop;
			m_minLinkTop = tempNode;
		}

	}

	//

	void push(int value)
	{
		StackNode* tempNode = new StackNode(value);
		StackNode* tempMinNode = new StackNode(value);;
		if (nullptr == m_stackTop)
		{
			m_stackTop = tempNode;
			m_minLinkTop = tempMinNode;
		}
		else
		{
			tempNode->m_prev = m_stackTop;
			m_stackTop = tempNode;
			// check min value
			if (m_minLinkTop->m_val >= tempMinNode->m_val)
			{
				tempMinNode->m_prev = m_minLinkTop;
				m_minLinkTop = tempMinNode;
			}
		}
	}

	void pop()
	{
		if (m_stackTop->m_prev != nullptr)
		{
			StackNode* tempNode = m_stackTop;
			m_stackTop = m_stackTop->m_prev;
			tempNode->m_prev = nullptr;
			int tempVal = tempNode->m_val;
			delete tempNode;
			if (m_minLinkTop->m_val == tempVal)
			{
				tempNode = m_minLinkTop;
				m_minLinkTop = m_minLinkTop->m_prev;
				delete tempNode;
			}
		}
		else if (nullptr != m_stackTop)
			m_stackTop = m_minLinkTop = nullptr;

	}

	int top()
	{
		if (nullptr != m_stackTop)
			return m_stackTop->m_val;
		else
			return 0;
	}

	int getMin()
	{
		if (nullptr != m_minLinkTop)
			return m_minLinkTop->m_val;
		else
			return 0;
	}

private:
	StackNode* m_stackTop;
	StackNode* m_minLinkTop;
};