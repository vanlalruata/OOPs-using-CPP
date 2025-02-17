#include <iostream>
using namespace std;

int main() {
    string fullName;
    
    cout << "Enter your full name: ";
    getline(cin, fullName);  // Takes full line input

    cout << "Hello, " << fullName << "!" << endl;
    return 0;
}
