#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

template <int Max>
class Priority_Queue
{
public :
	Priority_Queue() : Array(new int[Max] {}) , Count(0)
	{

	}
	~Priority_Queue()
	{
		delete[] Array;
	}

	inline int count() const noexcept { return Count; }
	void Clear() noexcept { Count = 0; }
	bool Empty() const noexcept { return Count ? true : false; }
	int  Front()
	{
		return *Array;
	}
	void Pop_Front()
	{
		if (Count == 0) throw __cpp_exceptions;

		PopShift();		
	}
	void Push (int Value)
	{
		if (Count == Max) throw __cpp_exceptions;
		AddElement(Value);	
	}
private:
	
	int* Array;
	int  Count;

	void AddElement (int Value) noexcept
	{
		if (Count == 0)
			(*Array) = Value;
		else
		{
			int ValueIndex = FindOrder(Value);
			PushShift(ValueIndex);
			Array[ValueIndex] = Value;
		}

		Count++;
	}
	int  FindOrder (int Value) const noexcept
	{

		if (Value <= *Array) return 0;
		if (Value >= *(Array + Count - 1)) return Count;

		int Begin = 0, End = Count - 1, Middle = (Begin + End) / 2;

		while (End >= Begin)
		{
			if (Array[Middle] < Value)
				Begin = Middle + 1;

			else if (Array[Middle] > Value)
				End = Middle - 1;

			else
				return Middle;

			Middle = (Begin + End) / 2;
		}

		return Begin;
	
	}
	void PushShift(unsigned int BeginIndex) noexcept
	{
		for (int i = Count; i > BeginIndex; i--)
			Array[i] = Array[i - 1];
	}
	void PopShift() noexcept
	{
		for (int i = 1; i < Count; i++)
			Array[i - 1] = Array[i];

		Count--;
	}
};

#endif // !PRIORITY_QUEUE_HPP

