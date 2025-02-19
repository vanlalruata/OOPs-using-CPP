#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int speed;

public:
    Car(string b, int s) {  // Constructor
        brand = b;
        speed = s;
        cout << "Car object created!" << endl;
    }

    ~Car() {  // Destructor
        cout << "Car object destroyed!" << endl;
    }

    void display() {  // Member function
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car myCar("Toyota", 180);
    myCar.display();
    return 0;
}
