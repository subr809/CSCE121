#include <iostream>
#include <cmath> 
#include <string> 
#include "Stack.h"


void push(Stack& s, double element) {
	if (s.length < s.capacity) {
		s.A[s.length] = element;
		s.length += 1;
	}
	else if(s.length == s.capacity) {
		double* myArray = new double[2 * s.capacity];
		for(int i = 0; i < s.length; ++i) {
			myArray[i] = s.A[i];
		}
		delete[] s.A;
		s.A = myArray;
		s.A[s.length] = element;
		s.length += 1;
		s.capacity *= 2;
	}
}


double pop(Stack& s) {
	if (s.length == 0) {
		return NAN;
	}
	double l = s.A[s.length - 1];
	s.length -= 1;
	return l;
}


