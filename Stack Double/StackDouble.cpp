#include <iostream>
#include <cmath> 
#include <string> 
#include "StackDouble.h"


void StackDouble::push(double element) {
	if (this->length < this->capacity) {
		this->A[this->length] = element;
		this->length += 1;
	}
	else if(this->length == this->capacity) {
		double* myArray = new double[2 * this->capacity];
		for(int i = 0; i < this->length; ++i) {
			myArray[i] = this->A[i];
		}
		delete[] this->A;
		this->A = myArray;
		this->A[this->length] = element;
		this->length += 1;
		this->capacity *= 2;
	}
}


double StackDouble::pop() {
	if (this->length == 0) {
		return NAN;
	}
	double l = this->A[this->length - 1];
	this->length -= 1;
	return l;
}