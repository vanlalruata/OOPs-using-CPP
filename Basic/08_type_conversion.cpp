#include <iostream>
using namespace std;

int main() {
    // Implicit type conversion
    int num = 10;
    double result = num; // int is implicitly converted to double
    cout << "Implicit conversion: " << result << endl;

    // Explicit type conversion
    double pi = 3.14159;
    int intPi = (int)pi; // Explicit cast
    cout << "Explicit conversion: " << intPi << endl;

    return 0;
}
