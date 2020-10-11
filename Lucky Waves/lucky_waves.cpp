#include <iostream>
using namespace std;
int main() {
	int i, longest, cardinality;
	unsigned long n;
	double maximum, sequence;
	cin >> n;
	longest = 0;  // Largest cardinality 
	cardinality = 1;
	maximum = -1.79769e308;
	for (i = 0; i < n; ++i) {
		cin >> sequence;    // Numbers from the sequence 
		if (sequence > maximum) {
			maximum = sequence;
			cardinality += 1;
			longest = cardinality;
		}
		else {
            cardinality = 1;
		}
	}
	cout << longest;
	return 0;
}
