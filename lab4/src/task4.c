#include <openssl/bn.h>
#include "bnlib.h"
#include <stdio.h>

// Digital signature program (actually the RSA decryption operation)

/////////////////////////////
// compiling command:
// gcc bn_sample.c -lcrypto

int main(int argc, char const *argv[])
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *d = BN_new(); // public key <e, n>
    BIGNUM *n = BN_new();
    BIGNUM *C = BN_new(); // cipher
    BIGNUM *M = BN_new(); // decrypted plaintext
    
    if (argc != 4)
    {
        printf("%d\n", argc);
        printf("Please input 'C', 'd' and 'n' in form of commnad-line parameters\n");
    }

    BN_hex2bn(&C, argv[1]);
    BN_hex2bn(&d, argv[2]);
    BN_hex2bn(&n, argv[3]);
    BN_mod_exp(M, C, d, n, ctx);
    
    print_BN_hex("Digital signature:", M);

    return 0;
}
