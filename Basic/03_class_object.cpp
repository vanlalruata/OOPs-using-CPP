#include <iostream>
#include <string>
using namespace std;

/**
 * @class Car
 * @brief A class representing a Car with brand and speed properties
 * @details This class demonstrates basic class and object creation in C++
 */
class Car {
private:
    string brand;
    int speed;

public:
    // Default constructor
    Car() : brand("Unknown"), speed(0) {}
    
    // Parameterized constructor
    Car(const string& b, int s) : brand(b), speed(s) {}
    
    // Copy constructor
    Car(const Car& other) : brand(other.brand), speed(other.speed) {}
    
    // Getter methods
    const string& getBrand() const { return brand; }
    int getSpeed() const { return speed; }
    
    // Setter methods with validation
    void setBrand(const string& b) {
        if (!b.empty()) brand = b;
    }
    
    void setSpeed(int s) {
        if (s >= 0) speed = s;
    }
    
    // Display method with formatted output
    void display() const {
        cout << "Car Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
    
    // Method to accelerate
    void accelerate(int increment) {
        if (increment > 0) {
            speed += increment;
            cout << brand << " accelerated to " << speed << " km/h" << endl;
        }
    }
    
    // Method to brake
    void brake(int decrement) {
        if (decrement > 0 && speed >= decrement) {
            speed -= decrement;
            cout << brand << " slowed down to " << speed << " km/h" << endl;
        }
    }
};

int main() {
    // Create car objects using different constructors
    Car car1;  // Default constructor
    car1.setBrand("Toyota");
    car1.setSpeed(180);
    
    Car car2("BMW", 200);  // Parameterized constructor
    
    Car car3 = car1;  // Copy constructor
    
    // Display car information
    cout << "=== Car Information ===" << endl;
    car1.display();
    car2.display();
    car3.display();
    
    // Demonstrate car operations
    cout << "\n=== Car Operations ===" << endl;
    car1.accelerate(20);
    car2.brake(30);
    
    // Use getter methods
    cout << "\n=== Car Details via Getters ===" << endl;
    cout << "Car 1 - Brand: " << car1.getBrand() << ", Speed: " << car1.getSpeed() << " km/h" << endl;
    cout << "Car 2 - Brand: " << car2.getBrand() << ", Speed: " << car2.getSpeed() << " km/h" << endl;

    return 0;
}
