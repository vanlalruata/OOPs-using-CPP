#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

string sha256(const string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    string name, email, cpuId = "CPU-12345678"; // Replace with real function
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Email: "; getline(cin, email);

    string keySource = name + email + cpuId;
    string serial = sha256(keySource).substr(0, 16); // 16-char HEX key

    cout << "Generated Key: " << serial << endl;
    return 0;
}
