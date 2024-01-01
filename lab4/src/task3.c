#include <openssl/bn.h>
#include "bnlib.h"
#include <stdio.h>

/*
Decryption program, given cipher C and private key <d, n>
e.g.
C = 8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F
d = 74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D
n = DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5
*/

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
        printf("Please input 'C', 'd' and 'n' in form of commnad-line parameters\n");
    }

    BN_hex2bn(&C, argv[1]);
    BN_hex2bn(&d, argv[2]);
    BN_hex2bn(&n, argv[3]);
    BN_mod_exp(M, C, d, n, ctx);
    
    print_BN_hex("Decrypted plaintext:", M);

    return 0;
}
