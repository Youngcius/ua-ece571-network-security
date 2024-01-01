#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    // char *a = "I love you";
    // char *b = "I love you too";
    char *a = "4C61756E63682061206D6973736C652E";
    char *b = "4C61756E63682061206D697373696C652E";
    if (strcmp(a, b) == 0)
    {
        printf("True");
        /* code */
    }
    else
    {
        printf("False");
    }

    return 0;
}
