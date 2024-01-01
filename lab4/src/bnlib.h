#include<openssl/bn.h>
// Big number computing library
void print_BN_hex(char *msg, BIGNUM *a)
{
    char *number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

void print_BN_dec(char *msg, BIGNUM *a)
{
    char *number_str = BN_bn2dec(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}