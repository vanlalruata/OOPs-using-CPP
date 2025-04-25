// Write a C++ program to create a base class Employee with virtual function calculateSalary(). Derive two classes FullTimeEmployee and PartTimeEmployee, and override calculateSalary() in both. Use runtime polymorphism to calculate salary based on user input for employee type

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;
public:
    Employee(const string& n, int i) : name(n), id(i) {}
    virtual double calculateSalary() const = 0; // Pure virtual function
    virtual void display() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID  : " << id << endl;
    }
    virtual ~Employee() {}
};

// Derived class for full-time employees
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
    FullTimeEmployee(const string& n, int i, double salary)
        : Employee(n, i), monthlySalary(salary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void display() const override {
        cout << "\nFull-Time Employee Details:\n";
        Employee::display();
        cout << "Monthly Salary: ₹" << fixed << setprecision(2) << monthlySalary << endl;
    }
};

// Derived class for part-time employees
class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(const string& n, int i, double rate, int hours)
        : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void display() const override {
        cout << "\nPart-Time Employee Details:\n";
        Employee::display();
        cout << "Hourly Rate  : ₹" << fixed << setprecision(2) << hourlyRate << endl;
        cout << "Hours Worked : " << hoursWorked << endl;
    }
};

int main() {
    Employee* emp = nullptr;
    int choice;

    cout << "Employee Salary Calculation\n";
    cout << "1. Full-Time Employee\n";
    cout << "2. Part-Time Employee\n";
    cout << "Enter employee type (1 or 2): ";
    cin >> choice;
    cin.ignore(); // Clear newline

    string name;
    int id;

    cout << "Enter employee name: ";
    getline(cin, name);
    cout << "Enter employee ID: ";
    cin >> id;

    if (choice == 1) {
        double salary;
        cout << "Enter monthly salary: ";
        cin >> salary;
        emp = new FullTimeEmployee(name, id, salary);
    } else if (choice == 2) {
        double rate;
        int hours;
        cout << "Enter hourly rate: ";
        cin >> rate;
        cout << "Enter hours worked: ";
        cin >> hours;
        emp = new PartTimeEmployee(name, id, rate, hours);
    } else {
        cout << "Invalid choice. Exiting program." << endl;
        return 1;
    }

    // Runtime polymorphism: base class pointer calls derived class methods
    emp->display();
    cout << "Calculated Salary: ₹" << fixed << setprecision(2)
         << emp->calculateSalary() << endl;

    delete emp; // Clean up
    return 0;
}




// Employee Salary Calculation
// 1. Full-Time Employee
// 2. Part-Time Employee
// Enter employee type (1 or 2): 1
// Enter employee name: Mapuia
// Enter employee ID: 101
// Enter monthly salary: 5000

// Full-Time Employee Details:
// Employee Name: Mapuia
// Employee ID  : 101
// Monthly Salary: ₹5000.00
// Calculated Salary: ₹5000.00
