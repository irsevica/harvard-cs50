// Encrypts based on key word --> shifts text input by the alpha character index of each letter of the keyword one by one.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_TXT_SIZE 256

int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        printf("USAGE: Missing password arg or salt arg - pass in like './crack myplaintextpass A7'.\n");
    }
    else
    {
        if (strlen(argv[2]) != 2)
        {
            printf("INVALID INPUT: Salt is not 2 characters long (allows integers)\n");
            exit(1);
        }
        else
        {
            char *hash_password = crypt(argv[1], argv[2]);
            printf("Your hashed password is: %s\n", hash_password);
        }
    }
}