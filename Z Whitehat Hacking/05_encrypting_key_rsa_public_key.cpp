#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

using namespace std;

void generateRSAKeys() {
    RSA* keypair = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    FILE* pubFile = fopen("public.pem", "wb");
    PEM_write_RSAPublicKey(pubFile, keypair);
    fclose(pubFile);

    FILE* privFile = fopen("private.pem", "wb");
    PEM_write_RSAPrivateKey(privFile, keypair, NULL, NULL, 0, NULL, NULL);
    fclose(privFile);

    RSA_free(keypair);
}

int main() {
    generateRSAKeys();
    cout << "RSA Keys Generated!" << endl;
    return 0;
}
