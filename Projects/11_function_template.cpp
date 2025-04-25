// Create a function template called findMax() that returns the maximum of three values. Demonstrate it using integers, floats, and strings

#include <iostream>
#include <string>
using namespace std;

// Function template to find the maximum of three values
template <typename T>
T findMax(const T& a, const T& b, const T& c) {
    T maxVal = a;
    if (b > maxVal)
        maxVal = b;
    if (c > maxVal)
        maxVal = c;
    return maxVal;
}

int main() {
    // Demonstrate with integers
    int x = 10, y = 25, z = 15;
    cout << "Max of " << x << ", " << y << ", " << z << " is: "
         << findMax(x, y, z) << endl;

    // Demonstrate with floats
    float f1 = 3.14f, f2 = 2.71f, f3 = 3.99f;
    cout << "Max of " << f1 << ", " << f2 << ", " << f3 << " is: "
         << findMax(f1, f2, f3) << endl;

    // Demonstrate with strings
    string s1 = "apple", s2 = "banana", s3 = "pear";
    cout << "Max of \"" << s1 << "\", \"" << s2 << "\", \"" << s3 << "\" is: \""
         << findMax(s1, s2, s3) << "\"" << endl;

    return 0;
}


// Max of 10, 25, 15 is: 25
// Max of 3.14, 2.71, 3.99 is: 3.99
// Max of "apple", "banana", "pear" is: "pear"