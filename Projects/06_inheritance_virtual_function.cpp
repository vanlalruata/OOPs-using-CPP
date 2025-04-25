// Write a C++ program that implements single inheritance and demonstrates virtual functions with a base class Shape and derived classes Circle and Square.

#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Base class
class Shape {
protected:
    string name;

public:
    // Constructor
    Shape(const string& n = "Shape") : name(n) {}

    // Virtual function to calculate area
    virtual double area() const {
        cout << "Area not defined for generic shape." << endl;
        return 0.0;
    }

    // Virtual function to display shape details
    virtual void display() const {
        cout << "Shape: " << name << endl;
    }

    // Virtual destructor
    virtual ~Shape() {
        cout << "Destroying Shape: " << name << endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : Shape("Circle"), radius(r) {}

    // Override area function
    double area() const override {
        return M_PI * radius * radius;
    }

    // Override display function
    void display() const override {
        cout << "Shape: " << name << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
    }

    // Destructor
    ~Circle() {
        cout << "Destroying Circle" << endl;
    }
};

// Derived class: Square
class Square : public Shape {
private:
    double side;

public:
    // Constructor
    Square(double s) : Shape("Square"), side(s) {}

    // Override area function
    double area() const override {
        return side * side;
    }

    // Override display function
    void display() const override {
        cout << "Shape: " << name << endl;
        cout << "Side: " << side << endl;
        cout << "Area: " << area() << endl;
    }

    // Destructor
    ~Square() {
        cout << "Destroying Square" << endl;
    }
};

// Helper function for positive input
double getPositiveInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cout << "Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}

int main() {
    cout << "Single Inheritance and Virtual Function Demonstration\n";
    cout << "1. Circle\n";
    cout << "2. Square\n";
    cout << "Choose a shape (1 or 2): ";

    int choice;
    cin >> choice;

    Shape* shapePtr = nullptr;

    if (choice == 1) {
        double r = getPositiveInput("Enter the radius of the circle: ");
        shapePtr = new Circle(r);
    } else if (choice == 2) {
        double s = getPositiveInput("Enter the side of the square: ");
        shapePtr = new Square(s);
    } else {
        cout << "Invalid choice. Exiting program." << endl;
        return 1;
    }

    cout << "\nDisplaying shape details using base class pointer:\n";
    shapePtr->display();

    // Clean up
    delete shapePtr;

    return 0;
}
