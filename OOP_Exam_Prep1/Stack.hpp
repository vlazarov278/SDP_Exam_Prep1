#ifndef STACK_H
#define STACK_H

#include <iostream>

const size_t INIT_CAPACITY = 64;

template <typename T>
class Stack
{
	T* data;

	size_t size;
	size_t capacity;

	void copyDataArray(const T* dataArray, size_t size);
	void copyFrom(const Stack<T>& other);
	void free();
	void resize(size_t capacity);

public:

	Stack();
	// Copy Constructor
	Stack(const Stack<T>& other);
	// Assignment Operator
	Stack<T>& operator=(const Stack<T>& other);
	// Destructor
	~Stack();

	bool isEmpty();
	size_t currentCapacity();

	void push(const T& element);
	T& pop();
	const T& top();
};

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

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	copyFrom(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	free();
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
size_t Stack<T>::currentCapacity()
{
	return capacity;
}

template <typename T>
void Stack<T>::push(const T& element)
{
	if (size >= capacity)
		resize(capacity * 2);

	// Assuming T is well-defined
	data[size++] = element;
}

template <typename T>
T& Stack<T>::pop()
{
	if (isEmpty())
		throw std::length_error("Stack is empty!");
	T toReturn = data[--size];

	if (size < capacity / 2 && capacity > 1)
		resize(capacity / 2);
	return toReturn;
}

template <typename T>
const T& Stack<T>::top()
{
	if (isEmpty())
		throw std::length_error("Stack is empty!");

	return data[size - 1];
}

#endif // !STACK_H
