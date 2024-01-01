#include <openssl/bn.h>
#include "bnlib.h"
#include <stdio.h>

/*
Find the private key, given p, q, and e
e.g.
p = F7E75FDC469067FFDC4E847C51F452DF
q = E85CED54AF57E53E092113E62F436F4F
e = 0D88C3
*/

/////////////////////////////
// compiling command:
// gcc bn_sample.c -lcrypto

int main(int argc, char const *argv[])
{
    /*
    the command input should be two prime numbers p & q and one , in hexadecimal
    e.g. ./cal_pri_key F7E75FDC469067FFDC4E847C51F452DF E85CED54AF57E53E092113E62F436F4F 0D88C3
    the main function will print the result (value of private key) in hexadecimal
    */

    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *p = BN_new(); // big prime number
    BIGNUM *q = BN_new(); // big prime number
    BIGNUM *p_minus_1 = BN_new();
    BIGNUM *q_minus_1 = BN_new();
    BIGNUM *one = BN_new();

    BIGNUM *e = BN_new(); // public key <e, n>
    BIGNUM *d = BN_new(); // private key <d,n>
    BIGNUM *n = BN_new();
    BIGNUM *phi = BN_new(); // Euler function of n

    if (argc != 4)
    {
        printf("Please input 'p', 'q' and 'e' in form of commnad-line parameters");
    }

    BN_dec2bn(&one, "1");
    BN_hex2bn(&p, argv[1]);
    BN_hex2bn(&q, argv[2]);
    BN_hex2bn(&e, argv[3]);
    BN_sub(p_minus_1, p, one);
    BN_sub(q_minus_1, q, one);
    BN_mul(n, p, q, ctx);
    BN_mul(phi, p_minus_1, q_minus_1, ctx);
    BN_mod_inverse(d, e, phi, ctx);

    print_BN_hex("Private key:", d);

    return 0;
}
