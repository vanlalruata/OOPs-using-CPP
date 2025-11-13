#include <iostream>

/**
 * @class Complex
 * @brief Represents a complex number and demonstrates operator overloading.
 */
class Complex {
private:
    // Data members are private to ensure encapsulation.
    double real;
    double imag;

public:
    // Constructor to initialize the complex number.
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    /**
     * @brief Overloads the + operator to add two Complex numbers.
     * @param other The Complex number to add.
     * @return A new Complex number that is the sum of the two.
     *
     * This is a const member function because it does not modify the object
     * on which it is called. The parameter is a const reference to avoid
     * making an unnecessary copy of the object being added.
     */
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // A friend function is used to overload the << operator for std::ostream.
    // It needs access to the private members 'real' and 'imag'.
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

/**
 * @brief Overloads the stream insertion operator (<<) for the Complex class.
 * @param os The output stream.
 * @param c The Complex object to output.
 * @return A reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    } else {
        os << " - " << -c.imag << "i";
    }
    return os;
}

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    // The overloaded + operator is called here.
    Complex c3 = c1 + c2;

    // The overloaded << operator is used for printing.
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    return 0;
}
