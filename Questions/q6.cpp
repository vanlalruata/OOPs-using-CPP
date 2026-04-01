#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    void setName(string n) {
        name = n;
    }
    string getName() {
        return name;
    }
    void setAge(int a) {
        age = a;
    }
    int getAge() {
        return age;
    }
};

int main() {
    Person p;
    p.setName("Alice");
    p.setAge(25);
    cout << "Name: " << p.getName() << endl;
    cout << "Age: " << p.getAge() << endl;
    return 0;
}