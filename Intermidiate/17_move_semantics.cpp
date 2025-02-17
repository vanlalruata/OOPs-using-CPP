#include <iostream>
#include <vector>
using namespace std;

class Data {
public:
    vector<int> values;

    Data() { cout << "Constructor" << endl; }

    Data(const Data& other) {  // Copy Constructor
        values = other.values;
        cout << "Copy Constructor" << endl;
    }

    Data(Data&& other) noexcept {  // Move Constructor
        values = move(other.values);
        cout << "Move Constructor" << endl;
    }
};

int main() {
    Data d1;
    d1.values = {1, 2, 3};

    Data d2 = move(d1);  // Move instead of copy

    return 0;
}
