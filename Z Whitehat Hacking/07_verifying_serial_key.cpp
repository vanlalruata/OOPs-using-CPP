#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

using namespace std;

void verifyKey(const unsigned char* encrypted, int length) {
    FILE* pubFile = fopen("public.pem", "rb");
    RSA* rsa = PEM_read_RSAPublicKey(pubFile, NULL, NULL, NULL);
    fclose(pubFile);

    unsigned char decrypted[256];
    RSA_public_decrypt(length, encrypted, decrypted, rsa, RSA_PKCS1_PADDING);
    
    cout << "Decrypted Serial Key: " << decrypted << endl;
    RSA_free(rsa);
}

int main() {
    unsigned char encryptedKey[256] = { /* Add Signed Key */ };
    verifyKey(encryptedKey, 256);
    return 0;
}
