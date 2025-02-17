#include <iostream>
using namespace std;

// Concept for arithmetic types (int, float, double)
template <typename T>
concept Arithmetic = requires(T a, T b) {
    a + b;
    a - b;
    a * b;
};

// Function constrained to arithmetic types
template <Arithmetic T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum of integers: " << add(10, 20) << endl;
    cout << "Sum of doubles: " << add(3.5, 2.5) << endl;
    // add("Hello", "World"); // Compile-time error
    return 0;
}

//Remember, this is a C++ version 20+ stuff.