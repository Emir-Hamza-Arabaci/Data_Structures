#ifndef QUEUE_HPP
#define QUEUE_HPP

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

		// Fundemental Functions
	void Push_Front(T Value)
	{
		if (Count == a) throw __cpp_exceptions;
		Array[Count] = Value;

		Count++;
	}
	inline T& Front() noexcept
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

