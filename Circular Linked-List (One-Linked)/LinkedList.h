#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

using namespace std;

class Node
{
public:

	int Value;

	// CONSTRUCTORS
	Node() : Value(0), NextNodePtr(nullptr) {} // Invalid Node
	Node(int Value) : Value(Value), NextNodePtr(nullptr) {}
	Node(int Value, Node& NextNode) : Value(Value)
	{
		Plug(NextNode);
	}

	~Node()
	{// Destructor is not necessary

	}

	// BASIC FUNCTIONS
	void Plug(Node& NextNode)
	{
		NextNodePtr = &NextNode;
	}
	void Plug(Node* NextNode)
	{
		NextNodePtr = NextNode;
	}
	void UnPlug()
	{
		NextNodePtr = nullptr;
	}
	Node* NextNode()
	{
		return NextNodePtr;
	}
private:
	Node* NextNodePtr;

};

class LinkedList
{
public: // FUCTIONS

	
	LinkedList() : FirstNode(nullptr),LastNode(nullptr),Count(0)
	{
	}	
	~LinkedList()
	{

		for (Node* Iter = FirstNode; Iter != LastNode;)
		{
			Node* Temp = Iter->NextNode();
			delete Iter;
			Iter = Temp;
		}

		delete LastNode;

	}
	
	
	int count() { return Count; }

	void Add(int Value)
	{
		if (Count == 0)
			AddFirstElement(Value);
		else
			AddRegularElement(Value);
	}
	int& operator[] (unsigned int Index)
	{
		return GetNodeAtIndex(Index)->Value;
	}
	void Print()
	{
		cout << "[";
		for (Node* Iter = FirstNode; Iter != LastNode; Iter = Iter->NextNode())
			cout << Iter->Value << ",";
		
		cout << LastNode->Value <<  "]";
	}
	void Remove()
	{
		if (Count == 0) throw __cpp_exceptions;

		RemoveFromEnd();

	}
	void Remove(unsigned int RemoveIndex)
	{
		if (Count == 0) throw __cpp_exceptions;

		RemoveFromIndex(RemoveIndex);
	}


private:

	Node* FirstNode;
	Node* LastNode;
	unsigned int Count;

	
	void AddFirstElement(int Value)
	{
		FirstNode = LastNode = new Node(Value);
		LastNode->Plug(FirstNode);
		Count++;
	}
	void AddRegularElement(int Value)
	{
		LastNode->Plug(new Node(Value));
		LastNode = LastNode->NextNode();
		LastNode->Plug(FirstNode);
		
		Count++;
	}

	
	void RegularRemove(unsigned int RemoveIndex)
	{
		Node* LeftNode = GetNodeAtIndex(RemoveIndex - 1);
		Node* RightNode = LeftNode->NextNode()->NextNode();

		delete (LeftNode->NextNode());

		LeftNode->Plug(RightNode);

		Count--;
	}
	void RemoveFromEnd()
	{
		Node* TempNode = GetNodeAtIndex(Count - 2);

		delete LastNode;
		LastNode = TempNode;

		LastNode->Plug(FirstNode);

		Count--;
	}
	void RemoveFromIndex(unsigned int RemoveIndex)
	{

		if ((Count % RemoveIndex) == Count - 1)
			RemoveFromEnd();
		
		else
			RegularRemove(RemoveIndex);

	}

	Node* GetNodeAtIndex(unsigned int Index)
	{
		int RealIndex = Index % Count;
		if (RealIndex == 0) return FirstNode;
		if (RealIndex == Count - 1) return LastNode;


		Node* Iterator = FirstNode;
		int i = 0;

		while (i < Index)
		{
			Iterator = Iterator->NextNode();
			i++;
		}

		return Iterator;


	}

};

#endif // !LINKEDLIST_HPP






