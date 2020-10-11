/*
BLAS Level 1 function definitions
*/
#include <iostream>
#include <cmath> 
#include "blas.h"

int amax(const double* x, const unsigned int len) {
	unsigned int i;
	double xnum = 0;
	double max = 0;
	unsigned int counter = 0;
	if (len == 0) {
		counter = -1;
	}
	for (i = 0; i < len; ++i) {
		xnum = fabs(x[i]);
		if (xnum > max) {
			max = xnum;
			counter = i;
			}
		}
    return counter;
}


double asum(const double* x, const unsigned int len) {
	unsigned int i;
	double sum = 0;
	for (i = 0; i < len; ++i) {
		sum += fabs(x[i]);
	}
    return sum;
}



void axpy(const double a, const double* x, double* y, const unsigned int len) {
	unsigned int i;
	for (i = 0; i < len; ++i) {
		y[i] = ((a * x[i]) + y[i]);
	}
}



void copy(const double* x, double* y, const unsigned int len) {
	unsigned int i;
    for (i = 0; i < len; ++i) {
		y[i] = x[i];
	}
}



double dot(const double* x, const double* y, const unsigned int len) {
	unsigned int i;
	double finaldot = 0;
	if (len == 0) {
		finaldot = 0;
	}
	for (i = 0; i < len; ++i) {
		finaldot += (x[i] * y[i]); 
	}
    return finaldot;
}



double norm2(const double* x, const unsigned int len) {
	unsigned int i;
	double sum = 0;
	double euclidean;
	for (i = 0; i < len; ++i) {
		sum += pow(x[i], 2);
	}
	euclidean = sqrt(sum);
    return euclidean;
}



void scale(const double a, double* x, const unsigned int len) {
	unsigned int i;
	for (i = 0; i < len; ++i) {
		x[i] = (a * x[i]);
	}
}


void swap(double* x, double* y, const unsigned int len) {
	unsigned int i;
	double s[sizeof(x)];
	for (i = 0; i < len; ++i) {
		s[i] = x[i];
	}
    for (i = 0; i < len; ++i) {
		x[i] = y[i];
		y[i] = s[i];
	}
}