#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int num = N;
    int counter = 1;
    int inc = 1;
    int dec = 1;
    while (N != 0) {
        cin >> N;
        if (N >= num && N != 0) {
            counter += 1;
            inc += 1;
            num = N;
            }
        if (N < num && N != 0) {
            counter += 1;
            dec += 1;
            num = N;
            }
        }
    if (counter == inc || counter == dec ) {
        cout << counter << " sorted" << endl;
    }
    else {
        cout << counter << " unsorted" << endl;
    }
    return 0;
}