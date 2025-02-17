#include <iostream>
using namespace std;

// Function prototype
int add(int a, int b);

void printMessage() {
    cout << "Hello from a function!" << endl;
}

int main() {
    printMessage();
    cout << "Sum: " << add(5, 10) << endl;
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
