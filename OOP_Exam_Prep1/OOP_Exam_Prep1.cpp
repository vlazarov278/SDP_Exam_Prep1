#include <iostream>
#include "Stack.hpp"

int main()
{
    Stack<int> s;
	for (size_t i = 0; i < 66; i++)
	{
		s.push(i + 1);
		std::cout << s.top() << std::endl;
	}
	std::cout << "----" << std::endl;
	std::cout << s.currentCapacity() << std::endl;
	std::cout << "----" << std::endl;
	for (size_t i = 0; i < 66; i++)
	{
		std::cout << s.pop() << std::endl;
	}
	std::cout << "----" << std::endl;
	std::cout << s.currentCapacity() << std::endl;
	std::cout << "----" << std::endl;
}