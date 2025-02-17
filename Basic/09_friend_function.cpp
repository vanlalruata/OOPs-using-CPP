#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    Box(int w) : width(w) {}

    // Friend function declaration
    friend void printWidth(Box b);
};

// Friend function definition
void printWidth(Box b) {
    cout << "Width of the box: " << b.width << endl;
}

int main() {
    Box box(20);
    printWidth(box);
    return 0;
}
