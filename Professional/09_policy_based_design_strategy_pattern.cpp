#include <iostream>
using namespace std;

class Strategy {
public:
    virtual void execute() = 0;
};

class StrategyA : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy A" << endl;
    }
};

class StrategyB : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy B" << endl;
    }
};

class Context {
    Strategy* strategy;
public:
    Context(Strategy* strat) : strategy(strat) {}
    void setStrategy(Strategy* strat) { strategy = strat; }
    void execute() { strategy->execute(); }
};

int main() {
    StrategyA a;
    StrategyB b;
    
    Context context(&a);
    context.execute();  // Strategy A
    context.setStrategy(&b);
    context.execute();  // Strategy B

    return 0;
}
