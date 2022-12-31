#pragma once
template <class X>
class node2
{
public:
	X Data;
	node2<X>* Next;

public:
	node2(X val)
	{
		this->Data = val;
		this->Next = NULL;
	}
};
template <class X>
class Stack
{
private:
	node2<X>* Top;

public:
	Stack()
	{
		this->Top = NULL;
	}
	bool isEmpty()
	{
		if (this->Top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Push(X val)
	{
		node2<X>* newNode = new node2<X>(val);
		newNode->Next = Top;
		this->Top = newNode;
	}
	void Pop()
	{
		if (isEmpty())
		{
			cout << "Stack empty " << endl;
			return;
		}
		else
		{
			//T = this->Top->Data;
			node2<X>* Temp = this->Top;
			this->Top = Top->Next;
			delete Temp;
			//return T;
		}
	}
	X Peak()
	{
		X T =0;
		if (isEmpty())
		{
			return T;
		}
		else
		{
			T = this->Top->Data;
			return T;
		}
	}
};