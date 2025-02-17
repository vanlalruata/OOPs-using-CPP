#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { // Constructor
        cout << "Constructor called!" << endl;
    }
    
    ~Demo() { // Destructor
        cout << "Destructor called!" << endl;
    }
};

int main() {
    Demo obj; // Constructor automatically invoked
    cout << "Inside main function" << endl;
    return 0;
} // Destructor automatically invoked when obj goes out of scope
