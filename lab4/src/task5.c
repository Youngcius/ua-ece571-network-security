#include <openssl/bn.h>
#include "bnlib.h"
#include <stdio.h>
#include <string.h>

/*
Verify digital signature program (actually the RSA encryption operation)
e.g.
M = Launch a missle. (needs to be converted to hexadecimal firstly)
S = 643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F
e = 010001 (this hex value equals to decimal 65537)
n = AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115
*/

/////////////////////////////
// compiling command:
// gcc bn_sample.c -lcrypto

int main(int argc, char const *argv[])
{

    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *e = BN_new(); // public key <e, n>
    BIGNUM *n = BN_new();
    BIGNUM *M = BN_new();     // plaintext
    BIGNUM *S = BN_new();     // digital signature
    BIGNUM *M_dec = BN_new(); // decrypted plaintext from digital signature

    if (argc != 5)
    {
        printf("Please input 'M', 'S', 'e' and 'n' in form of commnad-line parameters\n");
    }

    BN_hex2bn(&M, argv[1]);
    BN_hex2bn(&S, argv[2]);
    BN_hex2bn(&e, argv[3]);
    BN_hex2bn(&n, argv[4]);
    BN_mod_exp(M_dec, S, e, n, ctx);

    char *M_hex = BN_bn2hex(M);
    char *M_dec_hex = BN_bn2hex(M_dec);

    print_BN_hex("M_ori", M);
    print_BN_hex("M_dec", M_dec);

    if (strcmp(M_hex, M_dec_hex) == 0)
    {
        printf("True: the signature is from Alice\n");
    }
    else
    {
        printf("False: the signature is not from Alice\n");
    }

    return 0;
}
