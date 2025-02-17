#include <iostream>
#include <memory>  // For smart pointers
using namespace std;

class Sample {
public:
    Sample() { cout << "Constructor called" << endl; }
    ~Sample() { cout << "Destructor called" << endl; }
    void show() { cout << "Smart pointer example" << endl; }
};

int main() {
    unique_ptr<Sample> ptr = make_unique<Sample>();  // Unique Pointer
    ptr->show();

    // No need to delete manually, handled automatically
    return 0;
}
