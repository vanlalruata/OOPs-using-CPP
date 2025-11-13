#include <iostream>

/**
 * @class MyNumber
 * @brief A simple class to demonstrate user-defined type conversions.
 */
class MyNumber {
private:
    int value;

public:
    // A constructor that can be used for implicit conversion from int to MyNumber.
    // To prevent this, you can mark the constructor as 'explicit':
    // explicit MyNumber(int val) : value(val) {}
    MyNumber(int val) : value(val) {
        std::cout << "Constructor called: MyNumber(" << val << ")" << std::endl;
    }

    // A conversion operator to convert MyNumber to an int.
    operator int() const {
        std::cout << "Conversion operator 'operator int()' called." << std::endl;
        return value;
    }

    void print() const {
        std::cout << "MyNumber value: " << value << std::endl;
    }
};

int main() {
    std::cout << "--- Basic Type Conversions ---" << std::endl;

    // Implicit type conversion (promotion)
    int num_int = 10;
    double num_double = num_int; // int is implicitly converted to double
    std::cout << "Implicit conversion (int to double): " << num_double << std::endl;

    // Explicit type conversion (casting)
    // C-style cast: (int)pi - discouraged in modern C++
    // C++ style casts are preferred because they are more specific and safer.
    // static_cast: for conversions between related types (e.g., int to double).
    // dynamic_cast: for safe downcasting in class hierarchies.
    // const_cast: to add or remove constness.
    // reinterpret_cast: for low-level, unsafe conversions.
    double pi = 3.14159;
    int int_pi = static_cast<int>(pi); // Using static_cast for explicit conversion
    std::cout << "Explicit conversion (double to int) using static_cast: " << int_pi << std::endl;

    std::cout << "\n--- User-Defined Type Conversions ---" << std::endl;

    // Conversion from a basic type to a class object
    MyNumber num_obj = 25; // Implicit conversion from int to MyNumber using the constructor
    num_obj.print();

    std::cout << std::endl;

    // Conversion from a class object to a basic type
    int int_val = num_obj; // Implicit conversion from MyNumber to int using the conversion operator
    std::cout << "Value of int_val after conversion from MyNumber: " << int_val << std::endl;

    return 0;
}
