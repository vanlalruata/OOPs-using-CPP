//Write a C++ program to demonstrate function overloading by creating an area() function to calculate the area of a circle, rectangle, and triangle.

#include <iostream>
#include <cmath>    // For M_PI and sqrt
#include <limits>   // For input validation

using namespace std;

// Function to calculate area of a circle
double area(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate area of a rectangle
double area(double length, double width) {
    return length * width;
}

// Function to calculate area of a triangle using Heron's formula
double area(double a, double b, double c) {
    // Check if the sides can form a triangle
    if (a + b > c && a + c > b && b + c > a) {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    } else {
        cout << "Invalid triangle sides!" << endl;
        return -1;
    }
}

// Helper function to get positive double input
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
    int choice;
    cout << "Area Calculation using Function Overloading\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius = getPositiveInput("Enter the radius of the circle: ");
            cout << "Area of Circle: " << area(radius) << endl;
            break;
        }
        case 2: {
            double length = getPositiveInput("Enter the length of the rectangle: ");
            double width = getPositiveInput("Enter the width of the rectangle: ");
            cout << "Area of Rectangle: " << area(length, width) << endl;
            break;
        }
        case 3: {
            double a = getPositiveInput("Enter side a of the triangle: ");
            double b = getPositiveInput("Enter side b of the triangle: ");
            double c = getPositiveInput("Enter side c of the triangle: ");
            double triangleArea = area(a, b, c);
            if (triangleArea != -1)
                cout << "Area of Triangle: " << triangleArea << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
