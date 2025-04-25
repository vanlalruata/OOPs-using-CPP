// This program demonstrates the use of various data types in C++
// and how to perform input and output operations with them.

#include <iostream>   // For input and output
#include <string>     // For using the string data type

using namespace std;

int main() {
    // Declare variables of different data types
    int age;                // Integer type
    float height;           // Floating-point type (single precision)
    double weight;          // Floating-point type (double precision)
    char grade;             // Character type
    string name;            // String type

    // Input and output for string
    cout << "Enter your name: ";
    getline(cin, name);     // Use getline to read a full line (including spaces)

    // Input and output for int
    cout << "Enter your age: ";
    cin >> age;

    // Input and output for float
    cout << "Enter your height in meters (e.g., 1.75): ";
    cin >> height;

    // Input and output for double
    cout << "Enter your weight in kilograms (e.g., 68.5): ";
    cin >> weight;

    // Input and output for char
    cout << "Enter your grade (A, B, C, etc.): ";
    cin >> grade;

    // Display the values entered by the user
    cout << "\n--- Displaying Entered Information ---" << endl;
    cout << "Name   : " << name << endl;
    cout << "Age    : " << age << endl;
    cout << "Height : " << height << " meters" << endl;
    cout << "Weight : " << weight << " kg" << endl;
    cout << "Grade  : " << grade << endl;

    // Return 0 to indicate successful execution
    return 0;
}
