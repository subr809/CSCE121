#include <iostream> 
using namespace std;

int main() {
	long long n;
	long long i = 0;
	cout << "Enter n >= 0: ";
	cin >> n;
	cout << endl;
	long long count = 0;
	long long n1 = n;
	int prime;
	int primenumber;
	if (n == 1) {
		cout << "The number is 0! and 1! No prime factors";
	}
	else if (n == 0) {
		cout << "Not a factorial";
	}
	else if (n > 0) {
		while (n1 > 1) {
			i += 1;
			count += 1;
			if (n % i != 0) {
				cout << "Not a factorial";
				break;
			}
			n1 /= i;
		}
		for (i = 1; i <= count; ++i) {
			int high = 0;
			for (prime = 1; prime <= i; ++prime) {
				if (i % prime != 0) {
					high += 1;
				}
			}
			if (high == (i - 2)) {
				primenumber = i;
			}
		}
		if (n1 == 1) {
			cout << "The number is " << count << "!" << " The largest prime factor is " << primenumber;
			}
	}
	else if (n < 0) {
		cout << "Invalid input"; 
	}
	return 0; 
}