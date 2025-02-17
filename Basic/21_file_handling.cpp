#include <iostream>
#include <fstream>  // File handling library
using namespace std;

int main() {
    ofstream outFile("example.txt");  // Create and open a file

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Hello, this is a file example!" << endl;
    outFile.close();  // Close file

    cout << "Data written to file successfully." << endl;
    return 0;
}
