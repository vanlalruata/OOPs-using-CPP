// This program demonstrates the use of a union in C++
// A union allows storing different data types in the same memory location,
// but only one member can hold a value at any given time.

#include <iostream>
#include <cstring> // For strcpy
using namespace std;

// Define a union to store either an integer, a float, or a string (as a char array)
union Data {
    int intValue;
    float floatValue;
    char strValue[20];
};

int main() {
    Data data; // Declare a union variable

    // Store and display an integer
    data.intValue = 42;
    cout << "After assigning intValue:\n";
    cout << "intValue: " << data.intValue << endl;

    // Store and display a float (overwrites the previous value)
    data.floatValue = 3.14f;
    cout << "\nAfter assigning floatValue:\n";
    cout << "floatValue: " << data.floatValue << endl;
    // Note: intValue is now overwritten and may not be valid

    // Store and display a string (overwrites the previous value)
    strcpy(data.strValue, "Hello");
    cout << "\nAfter assigning strValue:\n";
    cout << "strValue: " << data.strValue << endl;
    // Note: floatValue is now overwritten and may not be valid

    // Demonstrate that only one member holds a valid value at a time
    cout << "\nAccessing all members after assigning strValue:" << endl;
    cout << "intValue: " << data.intValue << " (garbage value)" << endl;
    cout << "floatValue: " << data.floatValue << " (garbage value)" << endl;
    cout << "strValue: " << data.strValue << " (valid value)" << endl;

    return 0;
}


// Union Definition:
// The union Data can store an int, a float, or a char array (string), but only one at a time.
// Memory Sharing:
// All members share the same memory location. Assigning a new value to one member overwrites the previous value.
// Demonstration:
// The program assigns and prints each member, showing that only the last assigned member holds a valid value.


// After assigning intValue:
// intValue: 42

// After assigning floatValue:
// floatValue: 3.14

// After assigning strValue:
// strValue: Hello

// Accessing all members after assigning strValue:
// intValue: 1819043144 (garbage value)
// floatValue: 1.53999e+09 (garbage value)
// strValue: Hello (valid value)
