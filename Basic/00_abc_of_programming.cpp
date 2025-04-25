// This is a simple C++ program to demonstrate the use of int main(),
// header files, and basic input/output operations.

// Include the iostream header for input and output streams
#include <iostream>

// Use the standard namespace to avoid writing std:: before cout and cin
using namespace std;

// The main function: program execution starts here
int main() {
    
    // Declare an integer variable to store user input
    int number;

    // Output a message to the user
    cout << "Enter an integer: ";

    // Take input from the user and store it in the variable 'number'
    cin >> number;

    // Output the value entered by the user
    cout << "You entered: " << number << endl;

    // Return 0 to indicate successful program execution
    return 0;
}
