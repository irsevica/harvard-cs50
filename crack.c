// Encrypts based on key word --> shifts text input by the alpha character index of each letter of the keyword one by one.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char *crack(char *hash_password);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("USAGE: Missing password arg - pass in like './crack myhashedpassword'.\n");
        exit(1);
    }
    else
    {
        printf("Your hashed password is: %s\n", argv[1]);
    }
    
    char *hash_password = argv[1];

    printf("Attempting to crack %s.\n", hash_password);
    char *result = crack(hash_password);

    printf("Your password is: %s\n", result);
}

char* crack(char hash_password[])
{
    char arr_chars[53] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    int arr_char_len = strlen(arr_chars);
    char *pass;
    pass = (char *) malloc(5);
    pass[4] = '\0';

    char salt[3];
    memcpy(salt, hash_password, 2);
    salt[2] = '\0';

    for(int i = 0; i < arr_char_len; i++)
    {
        for( int x = 0; x < arr_char_len; x++)
        {
            for( int y = 0; y < arr_char_len; y++)
            {   
                for( int z = 0; z < arr_char_len; z++)
                {
                    if (arr_chars[z] == ' ')
                    {
                        pass[0] = '\0';
                    }
                    else
                    {
                        pass[0] = arr_chars[z];
                    }

                    if (arr_chars[y] == ' ')
                    {
                        pass[1] = '\0';
                    }
                    else
                    {
                        pass[1] = arr_chars[y];
                    }

                    if (arr_chars[x] == ' ')
                    {
                        pass[2] = '\0';
                    }
                    else
                    {
                        pass[2] = arr_chars[x];
                    }

                    if (arr_chars[i] == ' ')
                    {
                        pass[3] = '\0';
                    }
                    else
                    {
                        pass[3] = arr_chars[i];
                    }

                    if (strcmp(crypt(pass, salt), hash_password) == 0)
                    {
                        return pass;
                    }
                }

            }
        }
    }
  free(pass);
  pass = "Couldn't crack hash.";
  return pass;
}