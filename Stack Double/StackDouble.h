#ifndef STACKDOUBLE_H
#define STACKDOUBLE_H
#include <string>

class StackDouble {
	public: 
		StackDouble(double* A = new double[1], int capacity = 1, int length = 0);
		void push(double element);
		double pop();		
		~StackDouble() {
			delete [] A;
		}
	private:
		int capacity = 1;      
		int length = 0; 
		double* A = new double[1]; 
};

StackDouble::StackDouble(double *A, int capacity, int length) {
	this->A = A;
	this->capacity = capacity;
	this->length = length;
}

#endif