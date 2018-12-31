// Encrypts based on key word --> shifts text input by the alpha character index of each letter of the keyword one by one.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TXT_SIZE 256

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("ERROR: Missing key arg. Please enter string as argument to script call.\n");
    }
    else
    {
        for (int x = 0; x < strlen(argv[1]); x++)
        {
            if (isalpha(argv[1][x]) == 0)
            {
                printf("ERROR: Argument needs to be all alpha letters.\n");
                exit(1);
            }
        }

        // Get string to encrypt

        char *freetext = malloc(MAX_TXT_SIZE);
        int invalid_input;

        do
        {
            invalid_input = 0;
            printf("Please enter freetext to encrypt: ");
            if (fgets(freetext, MAX_TXT_SIZE, stdin) == NULL)
            {
                printf("Invalid input. Please enter string value.\n");
                invalid_input = 1;
            }
            else
            {
                printf("You entered: %s\n", freetext);
            }
        }
        while(invalid_input > 0);

        char encrypted_text[256];
        int x = strlen(argv[1]);

        for (int i = 0, y = 0; i < strlen(freetext); i++)
        {
            char cur_char = freetext[i];
            if (isalpha(cur_char))
            {
                int cur_txt_alpha_index = (tolower(cur_char) - 'a');
                int index_key = y % x;
                char key = argv[1][index_key];
                int cur_key_index = (tolower(key) - 'a');
                printf("%c\n",key);
                int encrypt_alpha_index = (cur_txt_alpha_index + cur_key_index) % 26;
                encrypted_text[i] = encrypt_alpha_index + 97;
                if (isupper(cur_char))
                {
                   encrypted_text[i] = toupper(encrypted_text[i]);
                }
                y++;
            }
            else
            {
                printf("\n");
                encrypted_text[i] = cur_char;
            }
        }

        printf("Your encrypted string: %s\n", encrypted_text);
    }

}