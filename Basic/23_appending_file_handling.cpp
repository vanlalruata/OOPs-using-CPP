#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.txt", ios::app); // Open file in append mode

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Appending new content to the file." << endl;
    outFile.close();

    cout << "Data appended successfully." << endl;
    return 0;
}
