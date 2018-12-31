#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("ERROR: Missing key arg. Please enter int as argument to script call.\n");
    }
    else
    {
        int key = atoi(argv[1]);

        // Conversion error handling
        
        if (key == 0)
        {
            printf("Invalid argument. You entered '%s', please enter integer for encryption key.\n", argv[1]);
        }

        // Get string to encrypt

        char freetext[256];
        int invalid_input;

        do
        {
            invalid_input = 0;
            printf("Please enter freetext to encrypt: ");
            int result = scanf("%s", freetext);
            if (result == EOF)
            {
                printf("Invalid input. Please enter string value.\n");
                invalid_input = 1;
            }
            else if (result == 0)
            {
            while (fgetc(stdin) != '\n') // Read until a newline is found
                ;
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
        for (int i = 0; i < strlen(freetext); i++)
        {
            char cur_char = freetext[i];
            if (isalpha(cur_char))
            {
                int cur_alpha_index = (tolower(cur_char) - 'a');
                int encrypt_alpha_index = (cur_alpha_index + key) % 26;
                encrypted_text[i] = encrypt_alpha_index + 97;
                if (isupper(cur_char))
                {
                   encrypted_text[i] = toupper(encrypted_text[i]);
                }
            }
            else
            {
                encrypted_text[i] = cur_char;
            }
        }

        printf("Your encrypted string: %s\n", encrypted_text);
    }

}