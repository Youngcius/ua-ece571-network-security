#include <cstdlib>
#include <iostream>
#include <string>
#define KEYSIZE 16

using namespace std;

int main(int argc, char const *argv[])
{

    // argv[1]: file name to write (append)
    // argv[2]: random seed start number
    // argv[3]: random seed end numebr
    
    if (argc < 3)
    {
        printf("please input three command paramters\n");
    }
    else
    {
        int seed_start = atoi(argv[2]);
        int seed_end = atoi(argv[3]);
        int N = seed_end - seed_start + 1; // totally N keys
        const char *fname = argv[1];
        unsigned char keys[N][KEYSIZE];

        for (size_t k = 0; k < N; k++)
        {
            // k-th generated key
            srand(seed_start + k);
            for (size_t i = 0; i < KEYSIZE; i++)
            {
                keys[k][i] = rand() % 256;
            }
        }

        // write the generated key into text files
        FILE *fp;
        fp = fopen(fname, "w");

        for (size_t k = 0; k < N; k++)
        {
            for (size_t i = 0; i < KEYSIZE; i++)
            {
                fprintf(fp, "%.2x", keys[k][i]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    }
}