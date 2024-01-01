#include <openssl/bn.h>
#include "bnlib.h"
#include <stdio.h>

/*
Encryption program, given plaintext M and public key <e, n>
e.g.
M = A top secret!
e = 010001 (this hex value equals to decimal 65537)
n = DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5
*/

/////////////////////////////
// compiling command:
// gcc bn_sample.c -lcrypto

int main(int argc, char const *argv[])
{

    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *e = BN_new(); // public key <e, n>
    BIGNUM *n = BN_new();
    BIGNUM *M = BN_new(); // plaintext
    BIGNUM *C = BN_new(); // encrypted cipher

    if (argc != 4)
    {
        printf("Please input 'M', 'e' and 'n' in form of commnad-line parameters\n");
    }

    BN_hex2bn(&M, argv[1]);
    BN_hex2bn(&e, argv[2]);
    BN_hex2bn(&n, argv[3]);
    BN_mod_exp(C, M, e, n, ctx);

    print_BN_hex("Encrypted cipher:", C);

    return 0;
}
