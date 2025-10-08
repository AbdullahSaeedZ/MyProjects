#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{

protected:

	int _Size = 0;

public:

	class Node
	{
	public:
		T _Value;
		Node* Next;
		Node* Prev;
	};

	Node* Head = nullptr;
	Node* Tail = nullptr;
	

	void InsertAtBeginning(const T &Value)
	{
		Node* New_Node = new Node();
		New_Node->_Value = Value;
		New_Node->Next = Head;
		New_Node->Prev = nullptr;

		if (Head == nullptr)
		{
			Head = Tail = New_Node;
		}
		else
		{
			Head->Prev = New_Node;
			Head = New_Node;
		}

		++_Size;
	}

	void PrintList()
	{
		Node* Current = Head;

		while (Current != NULL)
		{
			cout << Current->_Value << " ";
			Current = Current->Next;
		}

	}

	Node* FindNodeByValue(const T& Value)
	{
		Node* Current = Head;

		while (Current != nullptr)
		{
			if (Current->_Value == Value)
				return Current;

			Current = Current->Next;
		}

		return nullptr;
	}

	void InsertAfter( Node* &Current, const T& Value)
	{
		if (Current == nullptr)
			return;

		Node* New_Node = new Node();
		New_Node->_Value = Value;
		New_Node->Next = Current->Next;
		New_Node->Prev = Current;

		if (Current->Next != nullptr)
			Current->Next->Prev = New_Node;
		else
			Tail = New_Node;

		Current->Next = New_Node;
		++_Size;
	}
	
	Node* GetNodeByIndex(int Index)
	{
		if (Index < 0 || Index >= _Size)
			throw std::out_of_range("Index not found"); //to throw exception and be handled by try-catch

		Node* Current = nullptr;

		if (Index < _Size / 2)
		{
			Current = Head;
			for (int NodeIndex = 0; NodeIndex < Index; ++NodeIndex)
			{
				Current = Current->Next;
			}
		}
		else
		{
			Current = Tail;
			for (int NodeIndex = _Size -1 ; NodeIndex > Index; --NodeIndex)
			{
				Current = Current->Prev;
			}
		}
		
		return Current;
	}

	void InsertAfter(int Index, const T& Value)
	{
		Node* NodeToInsertAfter = GetNodeByIndex(Index);
		InsertAfter(NodeToInsertAfter, Value);
	}

	void InsertAtEnd(const T& Value)
	{
		Node* New_Node = new Node();
		New_Node->_Value = Value;
		New_Node->Next = nullptr;
		New_Node->Prev = Tail;

		if (Tail == nullptr)
		{
			Head = Tail = New_Node;
		}
		else
		{
			Tail->Next = New_Node;
			Tail = New_Node;
		}

		++_Size;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (NodeToDelete == nullptr || Head == nullptr)
			return;

		if (NodeToDelete == Head)
		{
			Head = NodeToDelete->Next;
		}

		if (NodeToDelete == Tail)
		{
			Tail = NodeToDelete->Prev;
		}

		if (NodeToDelete->Next != nullptr)
		{
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		if (NodeToDelete->Prev != nullptr)
		{
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}

		delete NodeToDelete;
		--_Size;
	}

	void DeleteFirstNode()
	{
		if (Head == nullptr)
			return;

		Node* First_Node = Head;

		if (Head == Tail)
		{
			Head = Tail = nullptr;
		}
		else
		{
			Head = Head->Next;
			Head->Prev = nullptr;
		}

		delete First_Node;
		--_Size;
	}

	void DeleteLastNode()
	{
		if (Tail == nullptr)
			return;
	
		Node* Last_Node = Tail;

		if (Head == Tail)
		{
			Head = Tail = nullptr;
		}
		else
		{
			Tail = Tail->Prev;
			Tail->Next = nullptr;
		}
		
		delete Last_Node;
		--_Size;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return !_Size;
	}

	void Clear()
	{
		Node* Current = Head;

		while (Current != nullptr)
		{
			Node* Temp = Current;
			Current = Current->Next;
			delete Temp;
		}

		Head = Tail = nullptr;
		_Size = 0;
	}

	void Reverse()
	{
		if (Head == nullptr || Head->Next == nullptr)
			return;

		Node* Current = Head;
		Node* Temp = nullptr;

		while (Current != nullptr)
		{
			Temp = Current->Prev; // move the temp

			Current->Prev = Current->Next;
			Current->Next = Temp;

			Current = Current->Prev; // move the current
		}

		if (Temp != nullptr)
		{
			Tail = Head;
			Head = Temp->Prev;
		}
	}

	T GetNodeValueByIndex(int Index)
	{
		return GetNodeByIndex(Index)->_Value;
	}

	void UpdateNodeValueByIndex(int Index, const T& NewValue)
	{
		GetNodeByIndex(Index)->_Value = NewValue;
	}

};

