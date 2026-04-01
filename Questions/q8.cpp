#include <iostream>

using namespace std;

class Vehicle {
public:
    void move() {
        cout << "Vehicle moves" << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Car drives" << endl;
    }
};

class ElectricCar : public Car {
public:
    void charge() {
        cout << "ElectricCar charges" << endl;
    }
};

int main() {
    ElectricCar ec;
    ec.move();
    ec.drive();
    ec.charge();
    return 0;
}