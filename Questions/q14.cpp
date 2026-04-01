#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0; // pure virtual
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    s1->draw();
    Shape* s2 = new Rectangle();
    s2->draw();
    delete s1;
    delete s2;
    return 0;
}