#pragma once
template<class T>
class qnode {
public:
	T data;
	qnode<T>* next;
	qnode() {
		data = 0;
		next = NULL;
	}
	qnode(T e = 0) {
		data = e;
		next = NULL;
	}
};


//////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
class queue {
	
	qnode<T>* first;
	qnode<T>* last;
public:
	queue() {
		first = NULL;
		last = NULL;
	}

	bool isEmpty() const {
		return first == NULL;
	}

	void enqueue( T value) {
		if (isEmpty()) {
			first = new qnode<T>(value);
			last = first;
		}

		else {
			qnode<T>* p = new qnode<T>(value);
			last->next = p;
			last = last->next;
		}
	}

	T dequeue() {
		T ret_value;
		qnode<T>* temp;
		if (!isEmpty()) {
			ret_value = first->data;
			temp = first;
			first = first->next;
			delete(temp);
			return ret_value;
		}
	}

	void makenull() {
		while (!isEmpty())
			dequeue();
	}

};