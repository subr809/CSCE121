#include <iostream> 
#include "functions.h"
using namespace std;

int countDigitOccurrences (int n, int digit) {
	int threet, twot, thousands, hundreds, tens, ones;
	int count1 = 0; 
	if (n >= 100000) {
		threet = n / 100000;
		if (threet == digit) {
			count1 += 1;
		}
		n = n - (100000 * threet);
		twot = n / 10000; 
		if (twot == digit) {
			count1 += 1;
		}
		n = n - (10000 * twot);
		thousands = n / 1000; 
		if (thousands == digit) {
			count1 += 1;
		}
		n = n - (1000 * thousands);
		hundreds = n / 100; 
		if (hundreds == digit) {
			count1 += 1;
		}
		n = n - (100 * hundreds);
		tens = n / 10;
		if (tens == digit) {
			count1 += 1;
		}
		n = n - (10 * tens);
		ones = n;
		if (ones == digit) {
			count1 += 1;
		}
	}
	else if (n >= 10000) {
		twot = n / 10000; 
		if (twot == digit) {
			count1 += 1;
		}
		n = n - (10000 * twot);
		thousands = n / 1000; 
		if (thousands == digit) {
			count1 += 1;
		}
		n = n - (1000 * thousands);
		hundreds = n / 100; 
		if (hundreds == digit) {
			count1 += 1;
		}
		n = n - (100 * hundreds);
		tens = n / 10;
		if (tens == digit) {
			count1 += 1;
		}
		n = n - (10 * tens);
		ones = n;
		if (ones == digit) {
			count1 += 1;
		}
	}
	else if (n >= 1000) {
		thousands = n / 1000;
		if (thousands == digit) {
			count1 += 1;
		}
		n = n - (1000 * thousands);
		hundreds = n / 100;
		if (hundreds == digit) {
			count1 += 1;
		}
		n = n - (100 * hundreds);
		tens = n / 10;
		if (tens == digit) {
			count1 += 1;
		}
		n = n - (tens * 10);
		ones = n;
		if (ones == digit) {
			count1 += 1;
		}
	}
	else if (n >= 100) {
		hundreds = n / 100;
		if (hundreds == digit) {
			count1 += 1;
		}
		n = n - (100 * hundreds);
		tens = n / 10;
		if (tens == digit) {
			count1 += 1;
		}
		n = n - (tens * 10);
		ones = n;
		if (ones == digit) {
			count1 += 1;
		}
	}
	else if (n >= 10) {
		tens = n / 10;
		if (tens == digit) {
			count1 += 1;
		}
		n = n - (tens * 10);
		ones = n;
		if (ones == digit) {
			count1 += 1;
		}
	}
	else if (n < 10) {
		if (n == digit) {
			count1 += 1;
		}
	}
	return count1;
}