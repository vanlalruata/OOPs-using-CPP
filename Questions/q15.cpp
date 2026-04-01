#include <iostream>

using namespace std;

class Payment {
public:
    virtual void processPayment() = 0;
};

class CreditCard : public Payment {
public:
    void processPayment() override {
        cout << "Processing credit card payment" << endl;
    }
};

class UPI : public Payment {
public:
    void processPayment() override {
        cout << "Processing UPI payment" << endl;
    }
};

int main() {
    Payment* p1 = new CreditCard();
    p1->processPayment();
    Payment* p2 = new UPI();
    p2->processPayment();
    delete p1;
    delete p2;
    return 0;
}