// Demonstrate exception handling in C++ by writing a program that handles divide-by-zero and invalid input exceptions gracefully

#include <iostream>
#include <stdexcept> // For standard exceptions
#include <limits>    // For numeric_limits
using namespace std;

// Function to perform division and handle divide-by-zero
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Error: Division by zero is not allowed.");
    }
    return numerator / denominator;
}

// Function to get a valid double input from the user
double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a valid number." << endl;
        } else {
            return value;
        }
    }
}

int main() {
    cout << "C++ Exception Handling Demonstration\n";
    double num, denom, result;

    try {
        // Get valid numerator and denominator from user
        num = getValidDouble("Enter numerator: ");
        denom = getValidDouble("Enter denominator: ");

        // Attempt division
        result = divide(num, denom);

        cout << "Result: " << num << " / " << denom << " = " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    catch (const exception& e) {
        // Catch any other standard exceptions
        cout << "An error occurred: " << e.what() << endl;
    }
    catch (...) {
        // Catch-all for any other exceptions
        cout << "An unknown error occurred." << endl;
    }

    cout << "Program ended gracefully." << endl;
    return 0;
}



// C++ Exception Handling Demonstration
// Enter numerator: 10
// Enter denominator: 0
// Error: Division by zero is not allowed.
// Program ended gracefully.

// C++ Exception Handling Demonstration
// Enter numerator: abc
// Invalid input! Please enter a valid number.
// Enter numerator: 10
// Enter denominator: 2
// Result: 10 / 2 = 5
// Program ended gracefully.