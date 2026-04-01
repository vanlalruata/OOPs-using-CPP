#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    int year;
public:
    Car() {
        brand = "Toyota";
        year = 2020;
    }
    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Car c;
    c.display();
    return 0;
}