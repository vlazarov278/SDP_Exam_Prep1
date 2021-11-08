#ifndef STACK_H
#define STACK_H

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

	void push(const T& element);
	void pop();
	const T& top();
	bool isEmpty();
};

#endif // !STACK_H
