#include <iostream>
using namespace std;
#include <string>


void isArrayMonotonic(int array[], int size) {
    bool isAcc = true;
    bool isDec = true;

    for (int i = 0; i < size - 1; i++) {

        if (array[i] >= array[i + 1]) {
            isAcc = false;
        }
        if (array[i] < array[i + 1]) {
            isDec = false;
        }
    }

        if (isAcc || isDec) {
            cout << "Montonic" << endl;
        } else {
            cout << "Not Monotonic" << endl;
        }
}

int main() {
    int balance[4] = {1000, 1000, 2, 5};
    isArrayMonotonic(balance, 4);
}