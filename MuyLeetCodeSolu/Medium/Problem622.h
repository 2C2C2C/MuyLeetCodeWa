#pragma once

/*
622. Design Circular Queue
https://leetcode.com/problems/design-circular-queue/
*/

class MyCircularQueue
{
protected:
	int *data;
	int p_start;
	int p_tail;
	int size;
	int maxSize;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int _k);

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int _value);

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue();

	/** Get the front item from the queue. */
	int Front();

	/** Get the last item from the queue. */
	int Rear();

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty();

	/** Checks whether the circular queue is full or not. */
	bool isFull();

	//void showQueue();

	 // class end
};


//** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue::MyCircularQueue(int _k)
{
	data = new int[_k];
	p_start = 0;
	p_tail = 0;
	size = 0;
	maxSize = _k;
}

//** Insert an element into the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::enQueue(int _value)
{
	if (isFull())
	{
		//std::cout << "oh, the queue is full wa." << std::endl;
		return false;// full
	}
	else
	{
		//data.push_back(_value);
		if (size == 0)
			data[p_tail] = _value;
		else
		{
			if (++p_tail >= maxSize)
				p_tail = p_tail % maxSize;
			data[p_tail] = _value;
		}

		size++;
		//showQueue();
		return true;
	}
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::deQueue()
{
	if (isEmpty())
	{
		//std::cout << "oh, the queue is empty wa." << std::endl;
		return false; // empty
	}
	else
	{
		if (size > 1)
			data[p_start++] = 0;
		else
			data[p_start] = 0;

		size--;
		if (p_start >= maxSize)
			p_start = p_start % maxSize;

		return true;
	}
}

/** Get the front item from the queue. */
int MyCircularQueue::Front()
{
	if (isEmpty())
	{
		//std::cout << "the queue is empty" << std::endl;
		return -1;
	}
	else
	{
		return data[p_start];
	}
}

/** Get the last item from the queue. */
int MyCircularQueue::Rear()
{
	if (isEmpty())
	{
		//std::cout << "the queue is empty" << std::endl;
		return -1;
	}
	else
	{
		return data[p_tail];
	}
}

/** Checks whether the circular queue is empty or not. */
bool MyCircularQueue::isEmpty()
{
	return size == 0;
}

/** Checks whether the circular queue is full or not. */
bool MyCircularQueue::isFull()
{
	return size == maxSize;
	//return p_start == (p_tail + 1) % data.max_size() && data[p_start] != NULL;
}

