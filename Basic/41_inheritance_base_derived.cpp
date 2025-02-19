#include <iostream>
using namespace std;

class Person {
public:
    void info() {
        cout << "I am a person." << endl;
    }
};

class Employee {
public:
    void work() {
        cout << "I am working." << endl;
    }
};

class Manager : public Person, public Employee {
public:
    void manage() {
        cout << "I manage the team." << endl;
    }
};

int main() {
    Manager m;
    m.info();
    m.work();
    m.manage();
    return 0;
}
