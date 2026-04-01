#include <iostream>

using namespace std;

class Account {
private:
    double balance;
public:
    Account(double b = 0) {
        balance = b;
    }
    void deposit(double amt) {
        balance += amt;
    }
    void withdraw(double amt) {
        if (balance >= amt) balance -= amt;
        else cout << "Insufficient funds" << endl;
    }
    double checkBalance() {
        return balance;
    }
};

int main() {
    Account acc(1000);
    acc.deposit(500);
    acc.withdraw(200);
    cout << "Balance: " << acc.checkBalance() << endl;
    return 0;
}