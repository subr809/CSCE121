#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
	public: 
		Stack(T *A = new T[1], int capacity = 1, int length = 0);
		void push(T);
		T pop();	
		bool isEmpty();
		~Stack(){
			delete [] A;
		}
	private: 
		T *A = new T[1];
		int capacity = 1;
		int length = 0;
};

template <typename T>
Stack<T>::Stack(T *A, int capacity, int length) {
	this->A = A;	
	this->capacity = capacity;
	this->length = length;
}

template <typename T>
void Stack<T>::push(T element) {
	if (this -> length < this -> capacity) {
		this -> A[this->length] = element;
		this -> length += 1;
	}
	else if (this -> length == this -> capacity) {
		T *B = new T[2*this->capacity];
		for (int i = 0; i < this->length; ++i) {
			B[i] = this -> A[i];
		}
		delete[] this->A;
		this->A = B;
		this->A[this->length] = element;
		this->length += 1;
		this->capacity *= 2;
	}
}

template <typename T>
bool Stack<T>::isEmpty() {
	return (length == 0);
}

template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		exit(0);
	}
	T l = this -> A[this->length-1];
	this->length -= 1;
	return l;
}

#endif