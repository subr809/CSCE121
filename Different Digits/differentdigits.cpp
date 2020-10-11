#include <iostream>
#include "functions.h"
using namespace std;

int main() {
	int a, b, n, digit, total, digitcount, ncount, count;
	cout << "Enter numbers a <= b: ";
	cin >> a;
	cin >> b;
	total = (b-a) + 1;
	ncount = 0;
	if ((a <= 0 || b <= 0)) {
		cout << "Invalid input" << endl;
	}
	else if ((a > 10000 || b > 10000)) {
		cout << "Invalid input" << endl;
	}
	else if (b < a) {
		cout << "Invalid input" << endl; 
	}
	else {
		for (n = a; n <= b; ++n) {
			count = 0;
			for (digit = 0; digit <= 9; ++digit) {
				digitcount = countDigitOccurrences(n,digit);
				if (count == digitcount) {
					total = total;
					}
				else if (digitcount > 1) {
					if (n != ncount) {
						total -= 1;	
					}
				count = digitcount;
				ncount = n; 
				}
			}
		}
		cout << "There are " << total << " valid numbers between " << a << " and " << b << endl;
	}	
	return 0;
}