#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
};

int main() {
    Student s1 = {"Alice", 20};

    cout << "Name: " << s1.name << ", Age: " << s1.age << endl;
    return 0;
}
