#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>


using std::count;
using std::cin;


template <typename T, int Max>
class Queue
{
public:

		// Constructor and Destructor //
	Queue() : Array(new int[Max] {}), FirstIndex(0), Count(0)
	{

	}
	
	~Queue()
	{
		delete[] Array;
	}
		
		// Fundemental Functions // 

	void Push_Front(T Value)
	{
		if (Count == Max) throw __cpp_exceptions;
		GetMember(FirstIndex + Count) = Value;
		Count++;
	}

	void Pop_Front()
	{
		if (Count == 0) throw __cpp_exceptions;
		FirstIndex++;
		Count--;	
	}

	T& Front()
	{
		if (Count == 0) throw __cpp_exceptions;

		return GetMember(FirstIndex);
	}

	inline int count() noexcept { return Count; }
private:

	T* Array;
	int FirstIndex;
	int Count;

	T& GetMember(unsigned int Index) noexcept
	{
		return Array[CalculateActualIndex(Index)];
	}
	inline int CalculateActualIndex(unsigned int Index) noexcept
	{
		return Index % Max;
	}

};
#endif // !QUEUE_HPP

