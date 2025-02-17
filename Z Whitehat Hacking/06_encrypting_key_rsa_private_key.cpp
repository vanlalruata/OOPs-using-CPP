#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

using namespace std;

void signData(const string& data) {
    FILE* privFile = fopen("private.pem", "rb");
    RSA* rsa = PEM_read_RSAPrivateKey(privFile, NULL, NULL, NULL);
    fclose(privFile);

    unsigned char encrypted[256];
    int len = RSA_private_encrypt(data.size(), (unsigned char*)data.c_str(), encrypted, rsa, RSA_PKCS1_PADDING);
    
    cout << "Signed Key: ";
    for (int i = 0; i < len; i++) cout << hex << (int)encrypted[i];
    cout << endl;

    RSA_free(rsa);
}

int main() {
    signData("1234567890ABCDEF");
    return 0;
}
