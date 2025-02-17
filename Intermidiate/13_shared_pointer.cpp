#include <iostream>
#include <memory>
using namespace std;

class Sample {
public:
    Sample() { cout << "Constructor called" << endl; }
    ~Sample() { cout << "Destructor called" << endl; }
};

int main() {
    shared_ptr<Sample> ptr1 = make_shared<Sample>();
    shared_ptr<Sample> ptr2 = ptr1;  // Both share ownership

    cout << "Reference Count: " << ptr1.use_count() << endl;

    return 0;
}
