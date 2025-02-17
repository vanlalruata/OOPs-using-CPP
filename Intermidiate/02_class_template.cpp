#include <iostream>
using namespace std;

template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> intBox(100);
    Box<double> doubleBox(3.14);
    
    intBox.show();
    doubleBox.show();

    return 0;
}
