#include <iostream>
using namespace std;

template <typename T>
void wrapper(T&& arg) {
    cout << "Forwarding value: " << arg << endl;
}

template <typename T>
void forwardFunction(T&& arg) {
    wrapper(forward<T>(arg));  // Forwarding correctly
}

int main() {
    int x = 10;
    forwardFunction(x);  // L-value
    forwardFunction(20); // R-value

    return 0;
}
