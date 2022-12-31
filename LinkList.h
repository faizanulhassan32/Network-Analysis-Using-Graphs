#pragma once
#include<iostream>
using namespace std;
class Node {
public:
	int val;
	int idegree;

	Node* next;

	Node()
	{
		val = 0;
		idegree = 0;
		next = NULL;
	}

};

class List {
	Node* head;
	
public:
	int source;
	int  odegree;
	List() {
		head = NULL;
		source = 0;
		odegree = 0;
	}
	Node* getHead() {
		return head;
	}
	void add(int val)
	{
		Node* temp = new Node;
		temp->val = val;
		temp->idegree = 1;
		if (head == NULL)
			head = temp;
		else {
			Node* t = head;
			while (t->next != NULL)
				t = t->next;
			t->next = temp;
		}
	}
};
