#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setAge(int a) { age = a; }
    int getAge() { return age; }
};

class Student : public Person {
private:
    int roll;
public:
    void setRoll(int r) { roll = r; }
    int getRoll() { return roll; }
};

int main() {
    Student s;
    s.setName("John");
    s.setAge(20);
    s.setRoll(1);
    cout << "Name: " << s.getName() << endl;
    cout << "Age: " << s.getAge() << endl;
    cout << "Roll: " << s.getRoll() << endl;
    return 0;
}