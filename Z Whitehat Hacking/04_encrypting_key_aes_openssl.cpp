#include <iostream>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <cstring>

using namespace std;

void encryptAES(const string& plainText, unsigned char* key, unsigned char* iv, unsigned char* encrypted) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 256, &encryptKey);
    AES_cbc_encrypt((unsigned char*)plainText.c_str(), encrypted, plainText.size(), &encryptKey, iv, AES_ENCRYPT);
}

int main() {
    string plainText = "1234567890ABCDEF";
    unsigned char key[32], iv[AES_BLOCK_SIZE];

    RAND_bytes(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv));

    unsigned char encrypted[128] = {0};
    encryptAES(plainText, key, iv, encrypted);

    cout << "Encrypted Key (AES): ";
    for (int i = 0; i < plainText.size(); i++)
        cout << hex << (int)encrypted[i];
    cout << endl;
    return 0;
}
