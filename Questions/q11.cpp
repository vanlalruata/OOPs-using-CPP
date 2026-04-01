#include <iostream>

using namespace std;

class Shape {
public:
    virtual double area() {
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Shape* s = new Circle(5);
    cout << "Area: " << s->area() << endl;
    delete s;
    return 0;
}