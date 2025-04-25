// Create a class Student with data members name, roll, and marks. Use a constructor to initialize the object, and an inline function to display the student details. Demonstrate object creation and member access.

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float marks;

public:
    // Constructor to initialize data members
    Student(string n, int r, float m) : name(n), roll(r), marks(m) {}

    // Inline function to display student details
    inline void display() {
        cout << "Student Details:" << endl;
        cout << "Name  : " << name << endl;
        cout << "Roll  : " << roll << endl;
        cout << "Marks : " << marks << endl;
    }

    // Member access demonstration (getter)
    string getName() { return name; }
    int getRoll() { return roll; }
    float getMarks() { return marks; }
};

int main() {
    // Object creation using constructor
    Student s1("Alice", 101, 89.5f);
    Student s2("Bob", 102, 76.0f);

    // Display student details using inline function
    s1.display();
    cout << endl;
    s2.display();

    // Demonstrate member access using getter functions
    cout << "\nAccessing individual members of s1:" << endl;
    cout << "Name: " << s1.getName() << endl;
    cout << "Roll: " << s1.getRoll() << endl;
    cout << "Marks: " << s1.getMarks() << endl;

    return 0;
}
