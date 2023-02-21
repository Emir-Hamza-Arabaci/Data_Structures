#ifndef QUEUE_HPP
#include <iostream>

#define QUEUE_HPP

using std::cout;
using std::cin;

template <typename T, int a>
class Queue
{
	
public:

		// Constructor and Destructor
	Queue() : Array(new T[a] {}) , Count(0)
	{
	}
	~Queue()
	{
		delete[] Array;
	}

		// Helper Functions
	void Print() noexcept
	{
		cout << "[";
		for (int i = 0; i < a; i++)
			cout << *(Array + i) << ",";
		cout << "\b]";
	}

		// Fundemental Functions
	void Push_Front(T Value)
	{
		if (Count == a) throw __cpp_exceptions;
		Array[Count] = Value;

		Count++;
	}
	inline T Front() noexcept
	{
		return *Array;
	}
	
	void Pop_Front()
	{
		if (Count == 0) throw __cpp_exceptions;

		Shift();
		Count--;
	}
	
		// Getter Functions
	inline int count() noexcept { return Count; }

private:
	T* Array;
	int Count;

	void Shift() noexcept
	{
		for (int i = 1; i < Count; i++)
			Array[i - 1] = Array[i];
		
	}

};

#endif // !QUEUE.HPP

