

#include <iostream>

using namespace std;

class Node
{
public:
	int Value;

	// CONSTRUCTORS
	Node() : Value(0), NextNodePtr(nullptr), PreviousNodePtr(nullptr) {} // Invalid Node
	Node(int Value) : Value(Value), NextNodePtr(nullptr), PreviousNodePtr(nullptr) {}

	~Node()
	{// Destructor is not necessary

	}

	// BASIC FUNCTIONS
	void PlugNext(Node& NextNode)
	{
		NextNodePtr = &NextNode;
	}
	void PlugNext(Node* NextNode)
	{
		NextNodePtr = NextNode;
	}
	void PlugPrevious(Node& PreviousNode)
	{
		PreviousNodePtr = &PreviousNode;
	}
	void PlugPrevious(Node* PreviousNode)
	{
		PreviousNodePtr = PreviousNode;
	}
	void UnPlug()
	{
		NextNodePtr = nullptr;
		PreviousNodePtr = nullptr;
	}

	Node* NextNode()
	{
		return NextNodePtr;
	}
	Node* PreviousNode()
	{
		return PreviousNodePtr;

	}

private:
	Node* NextNodePtr;
	Node* PreviousNodePtr;

};

class LinkedList
{
public: // FUCTIONS

	//**
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
	
	//Getter
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
			cout << Iter->Value << ",";
		cout << "\b]";
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
		LastNode->PlugNext(TempNode);
		TempNode->PlugPrevious(LastNode);
		LastNode = TempNode;
		Count++;
	}

	int& operator[](unsigned int Index)
	{
		if(Node* Temp = GetNodeAtIndex(Index))
			return Temp->Value;

		throw __cpp_exceptions;
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
	void RegularRemove(unsigned int RemoveIndex)
	{
		// [PreviousNode]<->[CurrentNode]<->[NextNode]
		Node* CurrentNode = GetNodeAtIndex(RemoveIndex);
		Node* PreviousNode = CurrentNode->PreviousNode();
		Node* NextNode = CurrentNode->NextNode();

		delete CurrentNode;

		PreviousNode->PlugNext(NextNode);
		NextNode->PlugPrevious(PreviousNode);
		
		Count--;
	}
	void RemoveFromEnd()
	{
		Node* TempNode = LastNode->PreviousNode();
		delete LastNode;
		LastNode = TempNode;
		Count--;

		if (!LastNode) FirstNode = nullptr; // if LastNode eqls nullptr FirstNode must be nullptr;
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

		return nullptr;
	}

};


