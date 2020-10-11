int max(int a, int b) {
	int maximum;
	if (a > b) {
		maximum = a;
	}
	else {
		maximum = b;
	}
	return maximum;
}




double max(double a, double b) {
	double maximum;
	if (a > b) {
		maximum = a;
	}
	else {
		maximum = b;
	}
	return maximum;
}
char max(char a, char b) {
	int maximum;
	if (a > b) {
		maximum = a;
	}
	else {
		maximum = b;
	}
	return maximum;
}
	
int* max(int* A, int alen, int* B, int blen) {
	int* maximum = new int[max(alen, blen)];
	int min = 0;
	if (alen > blen) {
		min = blen;
	}
	else {
		min = alen;
	}
	for (int i = 0; i < min; ++i) {
		maximum[i] = max(A[i], B[i]);
	}
	if (alen < blen) {
		for (int j = min; j < max(alen, blen); ++j) {
			maximum[j] = B[j];
		}
	}
	else {
		for (int j = min; j < max(alen, blen); ++j) {
			maximum[j] = A[j];
		}
	}
	return maximum;
}

char* max(char* a, char* b) {
	for (int i = 0; i < 255; ++i) {
		if(a[i] == '\0' && b[i] != '\0') {
			return b;
		}
		else if (a[i] != '\0' && b[i] == '\0') {
			return a;
		}
		else {
			if (a[i] > b[i]) {
				return b;
			}
			if (a[i] < b[i]) {
				return a;
			}
		}
	}
	if (a > b) {
		return a;
	}
	return b;
}

int max(int a, int b, int c, int d, int e, int f) {
	int max = a;
	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}
	if (max < d) {
		max = d;
	}
	if (max < e) {
		max = e;
	}
	if (max < f) {
		max = f;
	}
	return max;	
}