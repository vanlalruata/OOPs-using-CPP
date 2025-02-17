#include <iostream>
using namespace std;

// Compile-time factorial computation using template metaprogramming
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

// Base case
template <>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    cout << "Factorial of 5: " << Factorial<5>::value << endl;
    return 0;
}
