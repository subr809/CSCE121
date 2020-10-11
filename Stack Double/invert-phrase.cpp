#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Stack<string> s;
	string input;
	std::getline(cin, input);
	string sentence = "";
	for (int i = 0; i < input.size()-1; ++i) {
		sentence += input[i];
	}
	int idx = sentence.find_first_of(" ");
	int words = 0;
	int start = 0;
	if (idx == -1) {
		string word = "";
		for (int i = start; i < sentence.size(); ++i) {
			word += sentence[i];
		}
		s.push(word);
		words += 1;
	}
	else {
		while (idx != -1) {
			string word = "";
			for (int i = start; i < idx; ++i) {
				word += sentence[i];
			}
			s.push(word);
			start = idx+1;
			words += 1;
			idx = sentence.find(" ", idx+1);
			if (idx == -1) {
				string word = "";
				for (int i = start; i < sentence.size(); ++i) {
					word += sentence[i];
				}
				s.push(word);
				words += 1;
			}
		}
	}
	for (int i = 0; i < words; ++i) {
		string word1 = s.pop();
		cout << word1 << " ";
	}
	cout << endl;
    return 0;
}