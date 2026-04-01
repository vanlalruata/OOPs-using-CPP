#include <iostream>

using namespace std;

class Teacher {
public:
    void teach() {
        cout << "Teaching" << endl;
    }
};

class Researcher {
public:
    void research() {
        cout << "Researching" << endl;
    }
};

class Professor : public Teacher, public Researcher {
public:
    void manage() {
        cout << "Managing" << endl;
    }
};

int main() {
    Professor p;
    p.teach();
    p.research();
    p.manage();
    return 0;
}