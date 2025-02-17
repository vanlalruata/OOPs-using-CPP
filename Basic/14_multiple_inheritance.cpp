#include <iostream>
using namespace std;

class A {
public:
    void showA() { cout << "Class A" << endl; }
};

class B {
public:
    void showB() { cout << "Class B" << endl; }
};

class C : public A, public B {};

int main() {
    C obj;
    obj.showA();
    obj.showB();
    return 0;
}
