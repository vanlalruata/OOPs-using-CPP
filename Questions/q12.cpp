#include <iostream>

using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived" << endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show(); // runtime polymorphism
    delete b;
    return 0;
}