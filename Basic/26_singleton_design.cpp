#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}  // Private constructor

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        cout << "Singleton Instance!" << endl;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    obj1->showMessage();
    cout << "Memory Address of obj1: " << obj1 << endl;
    cout << "Memory Address of obj2: " << obj2 << endl;  // Same as obj1

    return 0;
}
