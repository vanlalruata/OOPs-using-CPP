#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class function" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class function" << endl;
    }
};

int main() {
    Base* basePtr;
    Derived obj;
    basePtr = &obj;
    basePtr->show(); // Calls Derived class function due to virtual function
    return 0;
}
