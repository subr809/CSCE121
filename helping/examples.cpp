// main.cpp
#include <iostream>
#include "SmartPointer.h"

using std::cout, std::endl;

int main() {
  SmartPointer<int> a(7);
  SmartPointer<int> b(a);
  cout << "a: " << *a << endl;
  cout << "b: " << *b << endl << endl;
  b = 14;
  cout << "b = 14" << endl;
  cout << "a: " << *a << endl;
  cout << "b: " << *b << endl << endl;
  SmartPointer<int> c(11);
  cout << "c: " << *c << endl << endl;
  c = a;
  cout << "c = a" << endl;
  cout << "a: " << *a << endl;
  cout << "b: " << *b << endl;
  cout << "c: " << *c << endl << endl;
  c = 22;
  cout << "c = 22" << endl;
  cout << "a: " << *a << endl;
  cout << "b: " << *b << endl;
  cout << "c: " << *c << endl;
  return 0;
}
