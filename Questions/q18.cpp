#include <iostream>

using namespace std;

class Bird {
public:
    virtual void fly() {
        cout << "Bird flies" << endl;
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        cout << "Sparrow flies fast" << endl;
    }
};

int main() {
    Bird* b = new Sparrow();
    b->fly();
    delete b;
    return 0;
}