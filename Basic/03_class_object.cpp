#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int speed;

    void display() {
        cout << "Car Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.speed = 180;
    
    car1.display();

    return 0;
}
