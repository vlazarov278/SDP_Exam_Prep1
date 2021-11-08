#include "Stack.h"

template <typename T>
void Stack<T>::copyDataArray(const T* dataArray, size_t size)
{
	// This is an internal helper function
	for (size_t i = 0; i < size; i++)
	{
		// Assuming T is well-defined
		data[i] = dataArray[i];
	}
}

template <typename T>
void Stack<T>::copyFrom(const Stack<T>& other)
{
	data = new T[other.capacity];
	capacity = other.capacity;
	size = other.size;

	copyDataArray(other.data, size);
}

template <typename T>
void Stack<T>::free()
{
	delete[] data;
}

template <typename T>
void Stack<T>::resize(size_t capacity)
{
	// This resizes the data array without checking for loss of data
	T* oldArrayHolder = data;
	this->capacity = capacity;
	data = new T[capacity];
	copyDataArray(oldArrayHolder, size);

	// Free the old memory as to have no memory leak
	delete[] oldArrayHolder;
}

template <typename T>
Stack<T>::Stack() : capacity(INIT_CAPACITY), size(0)
{
	data = new T[INIT_CAPACITY];
}