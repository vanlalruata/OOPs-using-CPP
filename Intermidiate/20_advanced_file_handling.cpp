#include <iostream>
#include <fstream>
using namespace std;

class Employee {
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
    Employee emp[2];

    // Writing objects to file
    ofstream outFile("employees.dat", ios::binary);
    for (int i = 0; i < 2; i++) {
        emp[i].getData();
        outFile.write((char*)&emp[i], sizeof(emp[i]));
    }
    outFile.close();

    // Reading objects from file
    Employee empRead[2];
    ifstream inFile("employees.dat", ios::binary);
    for (int i = 0; i < 2; i++) {
        inFile.read((char*)&empRead[i], sizeof(empRead[i]));
        empRead[i].display();
    }
    inFile.close();

    return 0;
}
