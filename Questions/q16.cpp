#include <iostream>

using namespace std;

class Box {
private:
    int length;
    friend void display(Box b);
public:
    Box(int l) {
        length = l;
    }
};

void display(Box b) {
    cout << "Length: " << b.length << endl;
}

int main() {
    Box b(10);
    display(b);
    return 0;
}