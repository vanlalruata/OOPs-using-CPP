// Write a program to read and write data to a file using fstream classes. Store and retrieve a list of employee names and their salaries

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to hold employee data
struct Employee {
    string name;
    double salary;
};

// Function to write employee data to a file
void writeToFile(const string& filename, const vector<Employee>& employees) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& emp : employees) {
        fout << emp.name << "," << emp.salary << endl;
    }
    fout.close();
    cout << "Employee data written to file successfully.\n";
}

// Function to read employee data from a file
vector<Employee> readFromFile(const string& filename) {
    vector<Employee> employees;
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return employees;
    }
    string line;
    while (getline(fin, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            Employee emp;
            emp.name = line.substr(0, commaPos);
            emp.salary = stod(line.substr(commaPos + 1));
            employees.push_back(emp);
        }
    }
    fin.close();
    return employees;
}

int main() {
    string filename = "employees.txt";
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;
    cin.ignore(); // Clear newline from input buffer

    vector<Employee> employees;

    // Input employee data
    for (int i = 0; i < n; ++i) {
        Employee emp;
        cout << "Enter name of employee #" << (i + 1) << ": ";
        getline(cin, emp.name);
        cout << "Enter salary of " << emp.name << ": ";
        cin >> emp.salary;
        cin.ignore(); // Clear newline
        employees.push_back(emp);
    }

    // Write data to file
    writeToFile(filename, employees);

    // Read data from file
    cout << "\nReading employee data from file...\n";
    vector<Employee> loadedEmployees = readFromFile(filename);

    // Display loaded data
    cout << "\nEmployee List:\n";
    cout << left << setw(25) << "Name" << right << setw(10) << "Salary" << endl;
    cout << string(35, '-') << endl;
    for (const auto& emp : loadedEmployees) {
        cout << left << setw(25) << emp.name << right << setw(10) << fixed << setprecision(2) << emp.salary << endl;
    }

    return 0;
}



// Output
// Enter the number of employees: 2
// Enter name of employee #1: Tluangi
// Enter salary of Tluangi: 50000
// Enter name of employee #2: Remi
// Enter salary of Remi: 60000
// Employee data written to file successfully.

// Reading employee data from file...

// Employee List:
// Name                         Salary
// -----------------------------------
// Tluangi                     50000.00
// Remi                        60000.00