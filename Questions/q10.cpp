#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    cout << add(1, 2) << endl;
    cout << add(1.5f, 2.5f) << endl;
    cout << add(1.5, 2.5) << endl;
    return 0;
}