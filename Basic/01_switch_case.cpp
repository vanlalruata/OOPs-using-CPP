// This program demonstrates the use of the switch-case statement in C++
// It acts as a simple calculator, performing an operation chosen by the user.

#include <iostream>  // Required for input and output operations
using namespace std;

int main() {
    int choice;         // Variable to store the user's menu choice
    double num1, num2;  // Variables to store the two numbers for calculation
    double result;      // Variable to store the result of the operation

    // Display a menu of operations to the user
    cout << "Simple Calculator using switch-case\n";
    cout << "-----------------------------------\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;  // Read the user's choice

    // Prompt the user to enter two numbers for the operation
    cout << "Enter first number: ";
    cin >> num1;    // Read the first number
    cout << "Enter second number: ";
    cin >> num2;    // Read the second number

    // The switch statement selects a block of code to execute based on the value of 'choice'
    switch (choice) {
        case 1: // If the user chose 1, perform addition
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break; // Exit the switch after executing this case

        case 2: // If the user chose 2, perform subtraction
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break; // Exit the switch after executing this case

        case 3: // If the user chose 3, perform multiplication
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break; // Exit the switch after executing this case

        case 4: // If the user chose 4, perform division
            // Check for division by zero to avoid runtime errors
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                // If the second number is zero, display an error message
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break; // Exit the switch after executing this case

        default: // If the user entered a number outside 1-4
            cout << "Invalid choice! Please run the program again and select 1-4." << endl;
            // No break needed here as this is the last case
    }

    // Return 0 to indicate successful program execution
    return 0;
}


// Simple Calculator using switch-case
// -----------------------------------
// 1. Addition
// 2. Subtraction
// 3. Multiplication
// 4. Division
// Enter your choice (1-4): 3
// Enter first number: 7
// Enter second number: 5
// Result: 7 * 5 = 35