#include <iostream>
#include <vector>

/**
 * @class Shape
 * @brief The base class for different geometric shapes.
 * @details This class demonstrates polymorphism through virtual functions.
 */
class Shape {
public:
    // A virtual destructor is essential for a polymorphic base class.
    // It ensures that the correct destructor is called when an object is
    // deleted through a base class pointer.
    virtual ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }

    /**
     * @brief A virtual function for drawing the shape.
     * 
     * A virtual function signals to the compiler that this function's behavior
     * can be overridden in derived classes. When called through a base class
     * pointer, the program will determine at runtime which version of the
     * function to call based on the actual type of the object. This is known
     * as dynamic dispatch or late binding.
     */
    virtual void draw() const {
        std::cout << "Drawing a generic shape." << std::endl;
    }
};

/**
 * @class Circle
 * @brief A derived class representing a circle.
 */
class Circle : public Shape {
public:
    ~Circle() {
        std::cout << "Circle destructor called." << std::endl;
    }

    // The 'override' specifier is a good practice. It makes the compiler
    // check that a virtual function with the same signature exists in the base class.
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

/**
 * @class Rectangle
 * @brief A derived class representing a rectangle.
 */
class Rectangle : public Shape {
public:
    ~Rectangle() {
        std::cout << "Rectangle destructor called." << std::endl;
    }

    void draw() const override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

int main() {
    // Create a collection of base class pointers to demonstrate polymorphism.
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());
    shapes.push_back(new Shape());

    std::cout << "--- Calling draw() on all shapes ---" << std::endl;
    // Loop through the shapes and call the virtual draw() function.
    // The correct 'draw' function is called for each object at runtime.
    for (const Shape* shapePtr : shapes) {
        shapePtr->draw();
    }

    std::cout << "\n--- Deleting all shapes ---" << std::endl;
    // Clean up the dynamically allocated memory.
    // The virtual destructor ensures the correct derived class destructor is called.
    for (Shape* shapePtr : shapes) {
        delete shapePtr;
    }
    shapes.clear();

    return 0;
}
