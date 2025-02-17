#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Multiply {
    int factor;
public:
    Multiply(int f) : factor(f) {}
    int operator()(int x) { return x * factor; }  // Overloading `()`
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    Multiply timesTwo(2);
    
    for (int &num : nums) {
        num = timesTwo(num);  // Using functor
    }

    cout << "Doubled values: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
