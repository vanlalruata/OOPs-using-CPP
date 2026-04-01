#include <iostream>
#include <string>

using namespace std;

class Calculator {
protected:
    string name1, name2;
public:
    Calculator(string n1, string n2) {
        name1 = n1;
        name2 = n2;
    }
    virtual int calculate() {
        return 50; // default
    }
};

class LoveCalculator : public Calculator {
public:
    LoveCalculator(string n1, string n2) : Calculator(n1, n2) {}
    int calculate() override {
        // simple logic, sum of ascii or something
        int sum = 0;
        for(char c : name1 + name2) sum += c;
        return sum % 101; // 0-100
    }
};

int main() {
    LoveCalculator lc("Alice", "Bob");
    cout << "Love percentage: " << lc.calculate() << "%" << endl;
    return 0;
}