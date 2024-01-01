#include <stdlib.h>
#include <stdio.h>
#define LEN 16 // 128 bits

int main(int argc, char const *argv[])
{
    unsigned char *key = (unsigned char *)malloc(sizeof(unsigned char) * LEN);
    FILE *random = fopen("/dev/urandom", "r");

    fread(key, sizeof(unsigned char) * LEN, 1, random);
    fclose(random);

    int i;
    for (i = 0; i < LEN; i++){
        key[i] = rand() % 256;
        printf("%.2x", (unsigned char)key[i]);
    }

    return 0;
}
