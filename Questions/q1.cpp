// Q1: Create a class Student with data members (name, roll, marks) and display the details using objects.
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;
};

int main() {
    Student s1;
    s1.name = "John";
    s1.roll = 1;
    s1.marks = 85.5;

    cout << "Name: " << s1.name << endl;
    cout << "Roll: " << s1.roll << endl;
    cout << "Marks: " << s1.marks << endl;

    return 0;
}