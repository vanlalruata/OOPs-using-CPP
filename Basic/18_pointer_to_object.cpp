#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int speed;

    void show() {
        cout << "Car Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car car1 = {"Tesla", 200};
    Car* ptr = &car1;  // Pointer to object

    ptr->show();  // Accessing using pointer
    return 0;
}
