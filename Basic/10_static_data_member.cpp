#include <iostream>
using namespace std;

class Counter {
private:
    static int count;

public:
    Counter() { count++; }

    static void showCount() {
        cout << "Count: " << count << endl;
    }
};

// Initialize static member
int Counter::count = 0;

int main() {
    Counter obj1, obj2, obj3;
    Counter::showCount();
    return 0;
}
