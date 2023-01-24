#include <iostream>

using namespace std;

class Node
{
public:
	int value() { return Value; }

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
	int Value;
	Node* NextNodePtr;

};

class LinkedList
{
public: // FUCTIONS
	LinkedList() : FirstNode(nullptr), LastNode(nullptr), Count(0)
	{
	}

	~LinkedList()
	{

		for (Node* Iter = FirstNode; Iter != nullptr;)
		{
			Node* Temp = Iter->NextNode();
			delete Iter;
			Iter = Temp;
		}

	}
	int count() { return Count; }

	void Add(int Value)
	{
		if (Count == 0)
			AddFirstElement(Value);
		else
			AddRegularElement(Value);
	}
	void Remove()
	{
		if (Count == 0) throw __cpp_exceptions;

		RemoveFromEnd();

	}
	void Remove(unsigned int RemoveIndex)
	{
		if (Count == 0) throw __cpp_exceptions;
		if (RemoveIndex >= Count) throw __cpp_exceptions;

		RemoveFromIndex(RemoveIndex);
	}
	void Print()
	{
		cout << "[";
		for (Node* Iter = FirstNode; Iter != nullptr; Iter = Iter->NextNode())
			cout << "," << Iter->value();
		cout << "]";
	}

private:

	Node* FirstNode;
	Node* LastNode;
	unsigned int Count;

	void AddFirstElement(int Value)
	{
		Node* TempNode = new Node(Value);
		FirstNode = LastNode = TempNode;
		Count++;
	}
	void AddRegularElement(int Value)
	{
		Node* TempNode = new Node(Value);
		LastNode->Plug(TempNode);
		LastNode = TempNode;
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
		TempNode->UnPlug();


		delete LastNode;
		LastNode = TempNode;

		Count--;
	}
	void RemoveFromIndex(unsigned int RemoveIndex)
	{
		if (RemoveIndex == Count - 1)
		{
			RemoveFromEnd();
			return;
		}
		else
			RegularRemove(RemoveIndex);

	}

	Node* GetNodeAtIndex(unsigned int Index)
	{
		if (Index == 0) return FirstNode;
		if (Index == Count - 1) return LastNode;
		if (Index < Count)
		{
			Node* Iterator = FirstNode;
			int i = 0;

			while (i < Index)
			{
				Iterator = Iterator->NextNode();
				i++;
			}

			return Iterator;
		}


	}

};


