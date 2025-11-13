#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/**
 * @class BankAccount
 * @brief A class demonstrating encapsulation principles in banking system
 * @details This class shows proper data hiding, validation, and controlled access
 */
class BankAccount {
private:
    double balance;
    string accountNumber;
    static int accountCounter;
    
    // Private helper methods
    void validateAmount(double amount) const {
        if (amount <= 0) {
            throw invalid_argument("Amount must be positive");
        }
    }

public:
    // Constructor with validation
    BankAccount(double initialBalance, const string& accNum = "")
        : balance(0.0), accountNumber(accNum) {
        try {
            validateAmount(initialBalance);
            balance = initialBalance;
            if (accountNumber.empty()) {
                accountNumber = "ACC" + to_string(++accountCounter);
            }
            cout << "Account created: " << accountNumber << " with initial balance: $" << balance << endl;
        } catch (const invalid_argument& e) {
            cout << "Error creating account: " << e.what() << endl;
            balance = 0;
        }
    }

    // Copy constructor
    BankAccount(const BankAccount& other)
        : balance(other.balance), accountNumber(other.accountNumber) {
        cout << "Account copied: " << accountNumber << endl;
    }

    // Assignment operator
    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            balance = other.balance;
            accountNumber = other.accountNumber;
        }
        return *this;
    }

    // Destructor
    ~BankAccount() {
        cout << "Account " << accountNumber << " destroyed. Final balance: $" << balance << endl;
    }

    // Getter methods (const qualified)
    double getBalance() const { return balance; }
    const string& getAccountNumber() const { return accountNumber; }

    // Controlled deposit operation
    bool deposit(double amount) {
        try {
            validateAmount(amount);
            balance += amount;
            cout << "Deposited $" << amount << " to " << accountNumber << endl;
            return true;
        } catch (const invalid_argument& e) {
            cout << "Deposit failed: " << e.what() << endl;
            return false;
        }
    }

    // Controlled withdrawal operation
    bool withdraw(double amount) {
        try {
            validateAmount(amount);
            if (amount > balance) {
                cout << "Withdrawal failed: Insufficient funds. Available: $" << balance << endl;
                return false;
            }
            balance -= amount;
            cout << "Withdrawn $" << amount << " from " << accountNumber << endl;
            return true;
        } catch (const invalid_argument& e) {
            cout << "Withdrawal failed: " << e.what() << endl;
            return false;
        }
    }

    // Transfer money to another account
    bool transfer(BankAccount& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            cout << "Transferred $" << amount << " from " << accountNumber
                 << " to " << recipient.accountNumber << endl;
            return true;
        }
        return false;
    }

    // Display account information
    void showBalance() const {
        cout << "Account: " << accountNumber << " | Balance: $" << balance << endl;
    }

    // Calculate interest (simple demonstration)
    void calculateInterest(double rate, int months) const {
        double interest = balance * (rate / 100) * (months / 12.0);
        cout << "Interest on $" << balance << " at " << rate << "% for "
             << months << " months: $" << interest << endl;
    }

    // Static method to get total accounts created
    static int getTotalAccounts() {
        return accountCounter;
    }
};

// Initialize static member
int BankAccount::accountCounter = 1000;

int main() {
    cout << "=== Banking System Demonstration ===" << endl;
    
    try {
        // Create bank accounts
        BankAccount account1(500.0, "ACC1001");
        BankAccount account2(1000.0);
        BankAccount account3 = account1; // Copy constructor
        
        cout << "\n=== Initial Accounts ===" << endl;
        account1.showBalance();
        account2.showBalance();
        account3.showBalance();
        
        cout << "\n=== Banking Operations ===" << endl;
        // Demonstrate various operations
        account1.deposit(200.0);
        account2.withdraw(150.0);
        
        // Demonstrate error handling
        cout << "\n=== Error Handling ===" << endl;
        account1.withdraw(-50.0); // Invalid amount
        account1.withdraw(1000.0); // Insufficient funds
        
        // Demonstrate transfer
        cout << "\n=== Transfer Operation ===" << endl;
        account1.transfer(account2, 300.0);
        
        // Calculate interest
        cout << "\n=== Interest Calculation ===" << endl;
        account1.calculateInterest(5.0, 12);
        
        cout << "\n=== Final Balances ===" << endl;
        account1.showBalance();
        account2.showBalance();
        
        cout << "\n=== Account Statistics ===" << endl;
        cout << "Total accounts created: " << BankAccount::getTotalAccounts() << endl;
        
    } catch (const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
    }
    
    return 0;
}
