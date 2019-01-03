#include <stdio.h>
int main(void)
{
    float dollar_val;
    int quarter = 25;
    int dime = 10;
    int nickle = 5;
    int penny = 1;
    int coins_used;
    int cent_val;

    // Handle invalid input
    int invalid_input;
    do 
    {
        invalid_input = 0;
        printf("Please input a dollar value: ");
        int result = scanf("%f", &dollar_val);
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
            printf("You entered: %f\n", dollar_val);
            cent_val = (int)dollar_val * 100;
            printf("In cents this is: %dc\n", cent_val);
        }
    }
    while (invalid_input == 1);

    int initial_cent_val = cent_val;

    while (cent_val >= quarter)
    {
        coins_used++;
        cent_val = cent_val - quarter;
    }

    while (cent_val >= dime)
    {
        coins_used++;
        cent_val = cent_val - dime;
    }

    while (cent_val >= nickle)
    {
        coins_used++;
        cent_val = cent_val - nickle;
    }
   
    while (cent_val >= penny)
    {
        coins_used++;
        cent_val = cent_val - penny;
    }

    printf("For %dc, %d coins were used.\n", initial_cent_val, coins_used);
}