#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
protected:
    string name;
public:
    void setId(int i) { id = i; }
    int getId() { return id; }
    void setName(string n) { name = n; }
    string getName() { return name; }
};

class Manager : public Employee {
public:
    void display() {
        cout << "Name: " << name << endl; // can access protected
        // cout << "ID: " << id << endl; // cannot access private
    }
};

int main() {
    Employee e;
    e.setId(1);
    e.setName("John");
    cout << "Employee ID: " << e.getId() << endl;
    cout << "Employee Name: " << e.getName() << endl;

    Manager m;
    m.setId(2);
    m.setName("Jane");
    m.display();
    return 0;
}