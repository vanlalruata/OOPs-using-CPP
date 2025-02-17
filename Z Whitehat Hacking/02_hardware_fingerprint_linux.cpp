#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string getCPUID() {
    string line, result;
    ifstream file("/sys/devices/virtual/dmi/id/product_uuid");
    if (file.is_open()) {
        getline(file, result);
        file.close();
    }
    return result;
}

int main() {
    cout << "CPU ID: " << getCPUID() << endl;
    return 0;
}
