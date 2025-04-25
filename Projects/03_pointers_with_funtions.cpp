// Create a C++ program that demonstrates the use of pointers with functions to swap two numbers. Include proper comments and explanation

#include <iostream>
using namespace std;

// Function to swap two numbers using pointers
void swapNumbers(int *a, int *b) {
    // Store the value pointed by a in a temporary variable
    int temp = *a;
    // Assign the value pointed by b to the location pointed by a
    *a = *b;
    // Assign the value stored in temp to the location pointed by b
    *b = temp;
    // Now, the values at the addresses have been swapped
}

int main() {
    int num1, num2;

    // Input two numbers from the user
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Display values before swapping
    cout << "\nBefore swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    // Call the swap function and pass the addresses of num1 and num2
    swapNumbers(&num1, &num2);

    // Display values after swapping
    cout << "\nAfter swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}
