#include "Vect.h"
#include <cstdlib>

Vect vect_construct(unsigned int n, int val) {
	Vect v;
	v.capacity = 2 * n;
	v.size = n;
	v.arr = new int[v.capacity];
	for (int i = 0; i < n; ++i) {
		v.arr[i] = val;
	}
	return v;
}

unsigned int vect_size(const Vect &v) {
	return v.size;
}

unsigned int vect_capacity(const Vect &v) {
	return v.capacity;
}

bool vect_empty(const Vect &v) {
	if (v.size == 0) {
		return true; 
	}
	else {
		return false;
	}
}

void vect_resize(Vect &v, unsigned int n) {
	if (n > v.size) {
		int* myar = new int[n];
		for (int i = 0; i < v.size; ++i) {
			myar[i] = v.arr[i];
		}
		delete[] v.arr;
		v.arr = myar;
		v.capacity = n;
	}
	else if (n < v.size) {
		int* myar = new int[n]; 
		for (int i = 0; i < n; ++i) {
			myar[i] = v.arr[i];
		}
		delete[] v.arr;
		v.arr = myar;
		v.capacity = n;
		v.size = n;
	}
}

int& vect_at(Vect &v, unsigned int idx){
	if (idx < 0 || idx > v.size - 1) {
		exit(1);
	}
	else {
		return v.arr[idx];
	}
}

void vect_erase(Vect &v, unsigned int idx) {
	if (idx < 0 || idx > v.size - 1) {
		exit(1);
	}
	for (int i = idx; i < v.size-1; ++i) {
		v.arr[i] = v.arr[i+1];
	}
	v.size -= 1;
}

void vect_push_back(Vect &v, int val) {
	if (v.size + 1 > v.capacity) {
		v.capacity *=2;
		int* myar = new int[v.capacity];
		for (int i = 0; i < v.size; ++i) {
			myar[i] = v.arr[i];
		}
		delete [] v.arr;
		v.arr = myar;
	}
	v.arr[v.size] = val;
	v.size += 1;
}

void vect_insert(Vect &v, unsigned int idx, int val) {
	if (idx < 0 || idx > v.size - 1) {
		exit(1);
	}
	if (v.size == v.capacity) {
		v.capacity *= 2;
		int* myar = new int[v.capacity];
		for (int i = 0; i < v.size; ++i) {
			myar[i] = v.arr[i];
		}
		delete[] v.arr;
		v.arr = myar;
	}
	for (int i = v.size; i > idx; --i) {
		v.arr[i] = v.arr[i - 1];
	}
	v.arr[idx] = val;
	v.size += 1;
}

void vect_clear(Vect &v) {
	if (v.size >= 20) {
		v.capacity = 20;
		int* myar = new int[v.capacity];
		delete[] v.arr;
		v.arr = myar; 
		v.size = 0;
	}
	else {
		v.size = 0;
	}
}

void vect_destruct(Vect &v) {
	v.size = 0;
	v.capacity = 0;
	for (int i = 0; i < v.size; ++i) {
		v.arr[i] = NULL;
		
	}
}