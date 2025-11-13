#include <iostream>
#include <stdexcept> // Required for std::runtime_error
#include <string>

/**
 * @class MyCustomException
 * @brief A custom exception class derived from std::exception.
 *
 * It's good practice to derive custom exceptions from std::exception.
 * This allows them to be caught by handlers for the base exception type.
 */
class MyCustomException : public std::exception {
private:
    std::string message;

public:
    MyCustomException(const std::string& msg) : message(msg) {}

    // Override the what() method to provide a custom error message.
    const char* what() const noexcept override {
        return message.c_str();
    }
};

/**
 * @brief A function that performs division and throws an exception on error.
 * @param a The numerator.
 * @param b The denominator.
 * @return The result of the division.
 * @throws std::runtime_error if the denominator is zero.
 */
double divide(int a, int b) {
    if (b == 0) {
        // Throwing a standard exception object is preferred over throwing
        // primitive types like const char* or int.
        throw std::runtime_error("Division by zero is not allowed.");
    }
    return static_cast<double>(a) / b;
}

/**
 * @brief A function that demonstrates throwing a custom exception.
 */
void processData(int data) {
    if (data < 0) {
        throw MyCustomException("Negative data is not allowed.");
    }
    std::cout << "Processing data: " << data << std::endl;
}

int main() {
    // --- Example 1: Handling a standard exception ---
    std::cout << "--- Example 1: Standard Exception ---" << std::endl;
    try {
        double result = divide(10, 0);
        std::cout << "Result of division: " << result << std::endl;
    }
    // It's best practice to catch exceptions by const reference.
    // This avoids unnecessary copying and object slicing.
    catch (const std::runtime_error& e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    }

    // --- Example 2: Handling different exception types ---
    std::cout << "\n--- Example 2: Multiple Catch Blocks ---" << std::endl;
    try {
        // Uncomment one of the following lines to test different exceptions:
        // processData(-5); // Throws MyCustomException
        // divide(20, 0);   // Throws std::runtime_error
        throw 404;       // Throws an integer
        
    }
    // Catch blocks are checked in order. The first one that matches the
    // exception type is executed.
    catch (const MyCustomException& e) {
        std::cout << "Caught my custom exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // This will catch std::runtime_error and any other exception
        // derived from std::exception that wasn't caught above.
        std::cout << "Caught a standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        // The catch-all block. This will catch any exception that was not
        // caught by the preceding blocks (e.g., an int, a char*, etc.).
        std::cout << "Caught an unknown exception type!" << std::endl;
    }

    std::cout << "\nProgram continues after exception handling." << std::endl;

    return 0;
}
