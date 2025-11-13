#include <iostream>

class Box; // Forward declaration of the Box class

// A friend function to overload the << operator for the Box class.
// This allows for easy printing of Box objects to output streams.
std::ostream& operator<<(std::ostream& os, const Box& b);

/**
 * @class Box
 * @brief A simple class to demonstrate friend functions.
 */
class Box {
private:
    int width;

public:
    Box(int w) : width(w) {}

    /**
     * A friend function is a function that is not a member of a class but has
     * access to the class's private and protected members.
     * 
     * They are declared inside the class with the 'friend' keyword.
     */

    // Declaration of a global function as a friend.
    friend void printWidth(const Box& b);

    // Declaration of the overloaded stream insertion operator as a friend.
    friend std::ostream& operator<<(std::ostream& os, const Box& b);
};

/**
 * @brief A friend function that prints the width of a Box.
 * @param b A const reference to a Box object to avoid unnecessary copying.
 * 
 * Since printWidth is a friend of Box, it can directly access private members like 'width'.
 */
void printWidth(const Box& b) {
    std::cout << "Width of the box: " << b.width << std::endl;
}

/**
 * @brief Overloaded stream insertion operator for the Box class.
 * @param os The output stream.
 * @param b The Box object to print.
 * @return A reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Box& b) {
    os << "Box(width: " << b.width << ")";
    return os;
}

int main() {
    Box box(20);

    // Calling the friend function.
    printWidth(box);

    // Using the overloaded << operator, which is also a friend function.
    std::cout << "Printing box using overloaded operator<<: " << box << std::endl;

    return 0;
}
