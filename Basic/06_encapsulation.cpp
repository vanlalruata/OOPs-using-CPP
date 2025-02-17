#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) { 
        balance = initialBalance; 
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void showBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account(500);
    account.deposit(200);
    account.withdraw(100);
    account.showBalance();

    return 0;
}
