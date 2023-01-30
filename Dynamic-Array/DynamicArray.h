#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP
#include <stdexcept>
template <class T>
class ArrayNode
{

	
public:
	ArrayNode<T>* NextNode, *PreviousNode;
public:
	//==============	CONSTRUCTOR(S) & DESTRUCTOR  ==============//
	ArrayNode() noexcept
	{
		NextNode = PreviousNode = nullptr;
		Size = Count = 0;
		ValueArray = nullptr;
	}

	ArrayNode(int ArraySize)
	{
		if (ArraySize <= 0)	throw std::invalid_argument("Array size cannot be a negative number.");

		NextNode = PreviousNode = nullptr;
		Size = ArraySize;
		Count = 0;
		ValueArray = new T[ArraySize];
	}

	~ArrayNode()
	{
		PreviousNode = NextNode = nullptr;
		Size = Count = 0;
		delete[] ValueArray;
	}

	//==============	FUNCTION(S)		=================//
		
	bool Add(T& Element)
	{
		if (Count > Size) return false; //Array is full

		ValueArray[Count] = Element;
		Count++;
		return true;
	}
	bool Remove()
	{//Remove from the end of the array

		if (Count == 0) return false; //Array is empty
		Count--;
		return true;
	}
	bool IsFull() { return Size == Count ? true : false; }
	unsigned int Count() { return Count; }
	unsigned int Size() { return Size; }

protected:
	T* ValueArray;
	unsigned int Size, Count;
private:
	
};

template <class T>
class Array
{
public:
	Array()
	{
		FirstNode = LastNode = nullptr;
		Count = Size = 0;
	}

	Array(unsigned int Size)
	{

	}

	void Add(T Element)
	{
		if(FirstNode)
		{// If firstNode is nullptr its means to the array is uninitialized.
			FirstAdd(Element);
			return;
		}

		if(LastNode->IsFull())
			ScaleUp(Size);

		RegularAdd(Element);

	}
	void Remove()
	{// Remove last element from at the end of the array
		if(Count == 0) // The array is already emty
			throw std::logic_error("List is already empty");
	}
protected:
	
private:
	ArrayNode<T> *FirstNode, *LastNode;
	unsigned int Count, Size;

private:
	void FirstAdd(T& Element)
	{
		FirstNode = LastNode = new ArrayNode<T>(1);
		FirstNode->Add(Element);
		Count++;
		Size = 1;
	}
	void ScaleUp(unsigned int NextScale)
	{
		ArrayNode<T>* TempNode = new ArrayNode<T>(NextScale);
		LastNode->NextNode = TempNode;
		Size += NextScale;
	}
	void RegularAdd(T& Element)
	{
		LastNode->Add(Element)
	}
	

};

#endif // !DYNAMIC_ARRAY_HPP

