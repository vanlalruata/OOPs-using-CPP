#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s;
    s.getData();

    // Writing object to file
    ofstream outFile("student.dat", ios::binary);
    outFile.write((char*)&s, sizeof(s));
    outFile.close();

    // Reading object from file
    Student s2;
    ifstream inFile("student.dat", ios::binary);
    inFile.read((char*)&s2, sizeof(s2));
    inFile.close();

    cout << "Data retrieved from file:" << endl;
    s2.display();

    return 0;
}
