#ifndef QUEUE_HPP
#define QUEUE_HPP

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

		// Helper Functions //
	void Print()
	{

	}
private:

	T* Array;
	int FirstIndex;
	int Count;

	T& GetMember(unsigned int Index)
	{
		return Array[CalculateActualIndex(Index)];
	}

	inline int CalculateActualIndex(unsigned int Index) noexcept
	{
		return Index % Max;
	}

};
#endif // !QUEUE_HPP

