// Develop a C++ program to read student records from a file, where each record contains roll number, name, and marks. Also write code to count and display how many students scored more than 75 marks

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

// Structure to hold student data
struct Student {
    int roll;
    string name;
    double marks;
};

// Function to read student records from a file
vector<Student> readStudentRecords(const string& filename) {
    vector<Student> students;
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: Could not open file '" << filename << "' for reading." << endl;
        return students;
    }

    string line;
    int lineNumber = 0;
    while (getline(fin, line)) {
        lineNumber++;
        istringstream iss(line);
        Student s;
        if (!(iss >> s.roll >> s.name >> s.marks)) {
            cerr << "Warning: Invalid record at line " << lineNumber << ". Skipping." << endl;
            continue;
        }
        students.push_back(s);
    }
    fin.close();
    return students;
}

// Function to display all student records
void displayStudents(const vector<Student>& students) {
    cout << left << setw(10) << "Roll No"
         << setw(15) << "Name"
         << setw(10) << "Marks" << endl;
    cout << string(35, '-') << endl;
    for (const auto& s : students) {
        cout << left << setw(10) << s.roll
             << setw(15) << s.name
             << setw(10) << fixed << setprecision(2) << s.marks << endl;
    }
}

// Function to count students with marks > 75
int countHighScorers(const vector<Student>& students, double threshold = 75.0) {
    int count = 0;
    for (const auto& s : students) {
        if (s.marks > threshold)
            count++;
    }
    return count;
}

int main() {
    string filename = "students.txt";

    // Read student records from file
    vector<Student> students = readStudentRecords(filename);

    if (students.empty()) {
        cout << "No valid student records found in the file." << endl;
        return 1;
    }

    // Display all student records
    cout << "\nStudent Records:\n";
    displayStudents(students);

    // Count and display students with marks > 75
    int highScorers = countHighScorers(students, 75.0);
    cout << "\nNumber of students who scored more than 75 marks: "
         << highScorers << endl;

    return 0;
}


// Create a file named students.txt in the same directory as your program, with content like:

// text
// 101 Alice 88.5
// 102 Bob 67
// 103 Carol 92
// 104 Dave 74
// 105 Eve 80






// Output Sample
// Student Records:
// Roll No   Name           Marks     
// -----------------------------------
// 101       Alice          88.50     
// 102       Bob            67.00     
// 103       Carol          92.00     
// 104       Dave           74.00     
// 105       Eve            80.00     

// Number of students who scored more than 75 marks: 3

