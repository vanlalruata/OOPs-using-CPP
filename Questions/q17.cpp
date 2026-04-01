#include <iostream>

using namespace std;

class A {
private:
    int a;
    friend void sum(A, B);
public:
    A(int x) {
        a = x;
    }
};

class B {
private:
    int b;
    friend void sum(A, B);
public:
    B(int y) {
        b = y;
    }
};

void sum(A obj1, B obj2) {
    cout << "Sum: " << obj1.a + obj2.b << endl;
}

int main() {
    A a(5);
    B b(10);
    sum(a, b);
    return 0;
}