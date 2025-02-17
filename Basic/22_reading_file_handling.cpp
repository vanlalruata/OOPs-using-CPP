#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("example.txt");  // Open file

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {  // Read file line by line
        cout << line << endl;
    }

    inFile.close();  // Close file
    return 0;
}
