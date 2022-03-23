#pragma once

#include "DynamicArray.h"

template<class T>
class PriorityQueue
{
private:
	DynamicArray<T> heap;

	int getParent(int i)
	{
		return (i - 1) / 2;
	}

	int getLeftChild(int i)
	{
		return 2 * i + 1;
	}

	int getRightChild(int i)
	{
		return 2 * i + 2;
	}

	void siftUp(int i)
	{
		while (heap[getParent(i)] < heap[i])
		{
			heap.swap(i, getParent(i));
			i = getParent(i);
		}
	}

	void siftDown(int i)
	{
		while (getLeftChild(i) < size())
		{
			int left = getLeftChild(i);
			int right = getRightChild(i);
			int j = left;
			if (right < size() && heap[left] < heap[right])
			{
				j = right;
			}
			if (!(heap[i] < heap[j]))
			{
				break;
			}
			heap.swap(i, j);
			i = j;
		}
	}

public:
	PriorityQueue()
	{
	}

	void push(T object)
	{
		heap.push_back(object);
		siftUp(size() - 1);
	}

	T top()
	{
		return heap[0];
	}

	void pop()
	{
		heap[0] = heap.pop_back();
		siftDown(0);
	}

	size_t size()
	{
		return heap.size();
	}

	bool empty()
	{
		return size() == 0;
	}
};