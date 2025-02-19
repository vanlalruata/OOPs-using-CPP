#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 10, y = 20;
    cout << "Sum: " << add(x, y) << endl;
    return 0;
}
