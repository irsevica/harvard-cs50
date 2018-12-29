/********************************************************
*   This is a simple C program that allows you to       *
*   determine whether a given credit card number        *
*   is a Visa, American Express, or MasterCard.         *
*                                                       *
*   Chris Callahan                                      *
*   Fall 2012 CS50 Hacker1 pset                         *
*********************************************************/

#include <stdio.h>

int main (void)
{
    long i, xadd, x2;
    int addsum, x2prod, sum;

    // get user's CC number ;)

    // Handle invalid input
    int invalid_input;
    do 
    {
        invalid_input = 0;
        printf("Please input a credit card value: ");
        int result = scanf("%ld", &i);
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
            printf("You entered: %ld\n", i);
        }
    }
    while (i <=0 || invalid_input == 1);

    // sum every other digit starting w/ the the last
    for ( xadd = i, addsum = 0; xadd > 0; xadd /= 100 )
        addsum += xadd % 10;

    // double every other digit starting w/ 2nd to last
    // then sum the individual digits of these products
    for ( x2 = i / 10, x2prod = 0; x2 > 0; x2 /= 100 )
    {
        if ( 2 * (x2 % 10) > 9 )
        {
            x2prod += (2 * (x2 % 10)) / 10;
            x2prod += (2 * (x2 % 10)) % 10;
        }
        else
            x2prod += 2 * (x2 % 10);
    }
    
    sum = addsum + x2prod;

    // check to see if the CC number is in the appropriate range
    if ( sum % 10 == 0 )
    {   
        if ( (i >= 340000000000000 && i < 350000000000000) || (i >= 370000000000000 && i < 380000000000000) )
            printf("AMERICAN EXPRESS\n");
        else if ( i >= 5100000000000000 && i < 5600000000000000 )
            printf("MASTERCARD\n");
        else if ( (i >= 4000000000000 && i < 5000000000000) || (i >= 4000000000000000 && i < 5000000000000000) )
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");

    return 0;
}
