#include <iostream>

using namespace std;

class Employee {
public:
    virtual double calculateSalary() {
        return 0;
    }
};

class Manager : public Employee {
public:
    double calculateSalary() override {
        return 50000;
    }
};

int main() {
    Employee* e = new Manager();
    cout << "Salary: " << e->calculateSalary() << endl;
    delete e;
    return 0;
}