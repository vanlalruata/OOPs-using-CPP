#include <iostream>
#include <type_traits>
using namespace std;

// Enable function only for integral types
template <typename T, typename enable_if<is_integral<T>::value, int>::type = 0>
void process(T x) {
    cout << "Processing integral type: " << x << endl;
}

// Enable function only for floating-point types
template <typename T, typename enable_if<is_floating_point<T>::value, int>::type = 0>
void process(T x) {
    cout << "Processing floating-point type: " << x << endl;
}

int main() {
    process(10);      // Calls integer overload
    process(3.14);    // Calls floating-point overload
    return 0;
}
