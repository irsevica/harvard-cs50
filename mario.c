#include <stdio.h>

int main(void)
{
    int height;
    // Handle invalid input
    int invalid_input;
    do 
    {
        invalid_input = 0;
        printf("Please input an integer value between 0 and 23: ");
        int result = scanf("%d", &height);
        if (result == EOF)
        {
            printf("Invalid input. Please enter integer.\n");
            invalid_input = 1;
        }
        else if (result == 0)
        {
          while (fgetc(stdin) != '\n') // Read until a newline is found
            ;
            printf("Invalid input. Please enter integer.\n");
            invalid_input = 1;
        }
        else
        {
            printf("You entered: %d\n", height);
        }
    }
    while (height < 0 || height > 23 || invalid_input == 1);

    printf("\n");
    printf("---- Right-aligned pyramid ----\n");
    printf("\n");

    // Pyramid logic based on user input - right aligned pyramid only
    for( int i = 1; i <= height; i++ )
    {
        int y = 0;
        int space_rqd = height - i;
        while (y < space_rqd)
        {
            printf(" ");
            y++;
        }
        int x = 0;
        while (x < i - 1)
        {
            printf("#");
            x++;
        }
        printf("#\n");
    }

    printf("\n");
    printf("---- Full pyramid ----\n");
    printf("\n");

    // Pyramid logic based on user input - full pyramid
    for( int i = 1; i <= height; i++ )
    {
        int y = 0;
        int space_rqd = height - i;
        while (y < space_rqd)
        {
            printf(" ");
            y++;
        }
        int x = 0;
        while (x < i)
        {
            printf("#");
            x++;
        }
        printf("  ");
        x = 0;
        while (x < i - 1)
        {
            printf("#");
            x++;
        }
        printf("#\n");
    }
}