#include <iostream>
#include <string>
#include <stdexcept>

/**
 * @class BankAccount
 * @brief A class demonstrating encapsulation principles in banking system
 * @details This class shows proper data hiding, validation, and controlled access
 */
class BankAccount {
private:
    double balance;
    std::string accountNumber;
    static int accountCounter;
    
    // Private helper methods
    void validateAmount(double amount) const {
        if (amount <= 0) {
            throw std::invalid_argument("Amount must be positive");
        }
    }

public:
    // Constructor with validation
    explicit BankAccount(double initialBalance, const std::string& accNum = "")
        : balance(0.0), accountNumber(accNum) {
        try {
            validateAmount(initialBalance);
            balance = initialBalance;
            if (accountNumber.empty()) {
                accountNumber = "ACC" + std::to_string(++accountCounter);
            }
            std::cout << "Account created: " << accountNumber << " with initial balance: $" << balance << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Error creating account: " << e.what() << std::endl;
            balance = 0;
        }
    }

    // Copy constructor
    BankAccount(const BankAccount& other)
        : balance(other.balance), accountNumber(other.accountNumber) {
        std::cout << "Account copied: " << accountNumber << std::endl;
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
        std::cout << "Account " << accountNumber << " destroyed. Final balance: $" << balance << std::endl;
    }

    // Getter methods (const qualified)
    double getBalance() const { return balance; }
    const std::string& getAccountNumber() const { return accountNumber; }

    // Controlled deposit operation
    bool deposit(double amount) {
        try {
            validateAmount(amount);
            balance += amount;
            std::cout << "Deposited $" << amount << " to " << accountNumber << std::endl;
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Deposit failed: " << e.what() << std::endl;
            return false;
        }
    }

    // Controlled withdrawal operation
    bool withdraw(double amount) {
        try {
            validateAmount(amount);
            if (amount > balance) {
                std::cout << "Withdrawal failed: Insufficient funds. Available: $" << balance << std::endl;
                return false;
            }
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from " << accountNumber << std::endl;
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Withdrawal failed: " << e.what() << std::endl;
            return false;
        }
    }

    // Transfer money to another account
    bool transfer(BankAccount& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            std::cout << "Transferred $" << amount << " from " << accountNumber
                 << " to " << recipient.accountNumber << std::endl;
            return true;
        }
        return false;
    }

    // Display account information
    void showBalance() const {
        std::cout << "Account: " << accountNumber << " | Balance: $" << balance << std::endl;
    }

    // Calculate interest (simple demonstration)
    void calculateInterest(double rate, int months) const {
        double interest = balance * (rate / 100) * (months / 12.0);
        std::cout << "Interest on $" << balance << " at " << rate << "% for "
             << months << " months: $" << interest << std::endl;
    }

    // Static method to get total accounts created
    static int getTotalAccounts() {
        return accountCounter;
    }
};

// Initialize static member
int BankAccount::accountCounter = 1000;

int main() {
    std::cout << "=== Banking System Demonstration ===" << std::endl;
    
    try {
        // Create bank accounts
        BankAccount account1(500.0, "ACC1001");
        BankAccount account2(1000.0);
        BankAccount account3 = account1; // Copy constructor
        
        std::cout << "\n=== Initial Accounts ===" << std::endl;
        account1.showBalance();
        account2.showBalance();
        account3.showBalance();
        
        std::cout << "\n=== Banking Operations ===" << std::endl;
        // Demonstrate various operations
        account1.deposit(200.0);
        account2.withdraw(150.0);
        
        // Demonstrate error handling
        std::cout << "\n=== Error Handling ===" << std::endl;
        account1.withdraw(-50.0); // Invalid amount
        account1.withdraw(1000.0); // Insufficient funds
        
        // Demonstrate transfer
        std::cout << "\n=== Transfer Operation ===" << std::endl;
        account1.transfer(account2, 300.0);
        
        // Calculate interest
        std::cout << "\n=== Interest Calculation ===" << std::endl;
        account1.calculateInterest(5.0, 12);
        
        std::cout << "\n=== Final Balances ===" << std::endl;
        account1.showBalance();
        account2.showBalance();
        
        std::cout << "\n=== Account Statistics ===" << std::endl;
        std::cout << "Total accounts created: " << BankAccount::getTotalAccounts() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }
    
    return 0;
}
