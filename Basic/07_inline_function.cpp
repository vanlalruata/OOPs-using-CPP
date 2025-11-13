#include <iostream>

/**
 * @class Calculator
 * @brief A simple class to demonstrate inline functions.
 */
class Calculator {
public:
    /**
     * @brief Calculates the square of a number.
     * @param x The integer to square.
     * @return The square of x.
     * 
     * The 'inline' keyword suggests to the compiler that it should perform
     * inline expansion for this function. Instead of a normal function call
     * (which involves jumping to a different part of the code and returning),
     * the compiler may substitute the function's code directly at the call site.
     * 
     * This can improve performance by avoiding the overhead of a function call,
     * especially for small, frequently used functions. However, it's only a
     * hint to the compiler, and the compiler can choose to ignore it.
     * 
     * Functions defined directly within a class definition are implicitly inline.
     */
    inline int square(int x) { 
        return x * x; 
    }
};

int main() {
    Calculator calc; // Create an instance of the Calculator class
    
    std::cout << "Square of 5: " << calc.square(5) << std::endl;
    std::cout << "Square of 8: " << calc.square(8) << std::endl;
    
    return 0;
}
