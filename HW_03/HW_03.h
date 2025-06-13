#pragma once

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>

class SimpleVector
{
public:

	SimpleVector() : currentSize(0), currentCapacity(10)
	{
		data = new T[currentCapacity];
	};

	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity)
	{
		data = new T[currentCapacity];
	}

	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity)
	{
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}
	}

	~SimpleVector()
	{
		release();
	};

	void push_back(const T& value)
	{
		if (currentSize >= currentCapacity)
		{
			resize(currentCapacity + 5);
		}
		data[currentSize++] = value;

	}

	void pop_back()
	{
		if (currentSize > 0)
		{
			--currentSize;
		}

	}

	int size()
	{
		return currentSize;
	}

	int capacity()
	{
		return currentCapacity;
	}

	void sortData() 
	{
		sort(data, data + currentSize);
		for (int i = 0; i < currentSize; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	void print()
	{
		for (int i = 0; i < currentSize; i++)
		{
			cout << data[i] << endl;
		}
	}

	void release()
	{
		delete[] data;
		data = nullptr;
	}

private:
	T* data;
	int currentSize;
	int currentCapacity;

	void resize(int newCapacity) 
	{
		if (newCapacity <= currentCapacity)
		{
			return;
		}

		T* newData = new T[newCapacity];
		for (int i = 0; i < currentSize; i++)
		{
			newData[i] = data[i];
		}

		release();
		data = newData;
		currentCapacity = newCapacity;
	}
};

