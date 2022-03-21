#pragma once

#include <exception>

template<class T>
class DynamicArray
{
private:
	T* m_array;
	size_t m_size;
	size_t m_capacity;

public:
	DynamicArray()
	{
		m_size = 0;
		m_capacity = 8;
		m_array = new T[m_capacity];
	}

	~DynamicArray()
	{
		delete[] m_array;
	}

	void push_back(T object)
	{
		if (m_size + 1 > m_capacity)
		{
			m_capacity *= 2;
			T* tmpArray = new T[m_capacity];
			for (size_t i = 0; i < m_size; ++i)
			{
				tmpArray[i] = m_array[i];
			}
			delete[] m_array;
			m_array = tmpArray;
		}
		m_array[m_size++] = object;
	}

	T pop_back()
	{
		if (m_size == 0)
		{
			throw std::exception("Warning: array is empty - can't pop an element");
		}
		return m_array[--m_size];
	}

	void swap(int i, int j)
	{
		T tmp = m_array[i];
		m_array[i] = m_array[j];
		m_array[j] = tmp;
	}

	size_t size()
	{
		return m_size;
	}

	T& operator[](int i)
	{
		if (i < 0 || i >= m_size)
		{
			throw std::exception("Index is out of range");
		}
		return m_array[i];
	}
};