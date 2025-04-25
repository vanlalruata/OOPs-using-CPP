// Write a C++ program that implements a class template for a stack, allowing operations like push and pop for both int and float data types.

#include <iostream>
#include <stdexcept>
using namespace std;

// Class template for Stack
template <typename T>
class Stack {
private:
    static const int MAX = 100; // Maximum stack size
    T arr[MAX];
    int top;

public:
    // Constructor
    Stack() : top(-1) {}

    // Push operation
    void push(const T& value) {
        if (top >= MAX - 1) {
            throw overflow_error("Stack Overflow: Cannot push, stack is full.");
        }
        arr[++top] = value;
    }

    // Pop operation
    T pop() {
        if (top < 0) {
            throw underflow_error("Stack Underflow: Cannot pop, stack is empty.");
        }
        return arr[top--];
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top < 0;
    }

    // Check if stack is full
    bool isFull() const {
        return top >= MAX - 1;
    }

    // Display stack contents
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Stack for int
    Stack<int> intStack;
    // Stack for float
    Stack<float> floatStack;

    cout << "Demonstrating Stack<int>:" << endl;
    try {
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.display();

        cout << "Popped: " << intStack.pop() << endl;
        intStack.display();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << "\nDemonstrating Stack<float>:" << endl;
    try {
        floatStack.push(1.1f);
        floatStack.push(2.2f);
        floatStack.push(3.3f);
        floatStack.display();

        cout << "Popped: " << floatStack.pop() << endl;
        floatStack.display();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
