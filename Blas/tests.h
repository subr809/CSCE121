#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::is_same;
using std::abs;
using std::ostream;

const double DBL_EQUALITY = 1e-6;

bool EXPECT_EQ(const int actual, const int expected, const string mssg) {
    if (actual == expected) {
        return true;
    } else {
        cout << "FAIL: " << mssg << endl;
        cout << "\t  actual: " << actual << endl;
        cout << "\texpected: " << expected << endl;
        return false;
    }
    return true;
}

bool EXPECT_EQ(const double actual, const double expected, const string mssg) {
    if (abs(actual - expected) < DBL_EQUALITY) {
        return true;
    } else {
        cout << "FAIL: " << mssg << endl;
        cout << "\t  actual: " << actual << endl;
        cout << "\texpected: " << expected << endl;
        return false;
    }
    return true;
}

template<typename T>
void print_array(const T* arr, const unsigned int len, ostream& out) {
    out << "[";
    if (len > 0) {
        out << arr[0];
    }
    unsigned int i = 1;
    while (i < len) {
        out << ", " << arr[i];
        i++;
    }
    out << "]";
}

bool EXPECT_EQ(const double* actual, const double* expected, const unsigned int len, const string mssg) {
    bool pass = true;
    for (unsigned int i = 0; i < len; i++) {
        if (abs(actual[i] - expected[i]) > DBL_EQUALITY) {
            pass = false;
            break;
        }
    }
    if (!pass) {
        cout << "FAIL: " << mssg << endl;
        cout << "\t  actual: ";
        print_array(actual, len, cout);
        cout << endl;
        cout << "\texpected: ";
        print_array(expected, len, cout);
        cout << endl;
    }
    return pass;
}
#endif