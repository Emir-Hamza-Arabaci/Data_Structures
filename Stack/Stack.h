
#ifndef STACK_HPP

#include <iostream>

#define STACK_HPP
#define MAX 100

using std::cout;

template <typename T>
class Stack
{
public :
	Stack() : count(0)
	{

	}

	void Push(T Value)
	{
		if (count >= MAX) return;

		Array[count] = Value;
		count++;
	}
	void Pop()
	{
		if (count > 0)
			count--;
		else
			throw __cpp_exceptions;
	}
	T Peek() 
	{
		if (count > 0)
			return Array[count - 1];
		else
			throw __cpp_exceptions;
	}

	void Print()
	{
		cout << "[";
		for (int i = count - 1; i >= 0; i--)
			cout << Array[i] << ",";
		cout << "\b]";
	}
	unsigned int Count()
	{
		return count;
	}
private:
	unsigned int count;
	T Array[MAX]{};

};

#endif // !STACK_HPP

