#include <iostream>
#include <cmath>
#include <string> 
#include "Stack.h"
using namespace std;

int main() {
	Stack s;
	string input;
	cin >> input;
	double left, right, result;
	while (input != "=") {
		if (input == "+") {
			left = pop(s);
			right = pop(s);
			result = left + right;
			push(s, result);
		}
		else if (input == "-") {
			left = pop(s);
			right = pop(s);
			result = right-left;
			push(s, result);
		}
		else if (input == "*") {
			left = pop(s);
			right = pop(s);
			result = left * right;
			push(s, result);
		}
		else if (input == "/") {
			left = pop(s);
			right = pop(s);
			result = right / left;
			push(s, result);
		}
		else {
			try {
				result = stod(input);
				push(s, result);
			}
			catch (const invalid_argument&) {
				cout << "[ERROR] invalid operator: " << input << endl;
				return 0;
			}
		}
		cin >> input;
	}
	cout << result;
	delete[] s.A;
	return 0;
}