#include <iostream>
using namespace std;

int globalVar = 100; // Global variable

void testScope() {
    int localVar = 50; // Local variable
    cout << "Inside function, localVar: " << localVar << endl;
    cout << "Inside function, globalVar: " << globalVar << endl;
}

int main() {
    int mainVar = 10; // Local to main()
    
    cout << "Inside main, mainVar: " << mainVar << endl;
    cout << "Inside main, globalVar: " << globalVar << endl;
    
    testScope();

    {
        int blockVar = 20; // Block-scoped variable
        cout << "Inside block, blockVar: " << blockVar << endl;
    }
    
    // cout << blockVar; // Error: blockVar is not accessible here
    
    return 0;
}
