// Write a program that demonstrates operator overloading for the + operator to add two complex numbers using a Complex class.

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor to initialize real and imaginary parts
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the + operator to add two Complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Function to display the complex number
    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main() {
    // Create two Complex objects
    Complex c1(3.5, 2.5);
    Complex c2(1.5, -4.5);

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    // Add two complex numbers using overloaded + operator
    Complex sum = c1 + c2;

    cout << "Sum of the two complex numbers: ";
    sum.display();

    return 0;
}


// Output
// First complex number: 3.5 + 2.5i
// Second complex number: 1.5 - 4.5i
// Sum of the two complex numbers: 5 + -2i