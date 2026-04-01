#include <iostream>

using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount(double b = 0) {
        balance = b;
    }
    void deposit(double amt) {
        balance += amt;
    }
    void withdraw(double amt) {
        if (balance >= amt) balance -= amt;
        else cout << "Insufficient balance" << endl;
    }
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc(1000);
    acc.deposit(500);
    acc.withdraw(200);
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}