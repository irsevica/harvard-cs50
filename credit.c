#include <stdio.h>
unsigned concatenate(unsigned x, unsigned y) 
{
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;      
}

int main(void)
{
    long cc_number;

    // Handle invalid input
    int invalid_input;
    do 
    {
        invalid_input = 0;
        printf("Please input a credit card value: ");
        int result = scanf("%ld", &cc_number);
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
            printf("You entered: %ld\n", cc_number);
        }
    }
    while (cc_number <=0 || invalid_input == 1);
    
    //calculate checksum
    long temp = cc_number;
    int checksum = 0;
    while (temp > 0)
    {
        long cur_num = (temp / 10) % 10;
        cur_num = (int)cur_num;
        int product = cur_num * 2;
        if (product >= 10)
        {
           int first_digit;
           while(product >=10)
           {
               first_digit = product / 10;
           }
           int last_digit = product % 10;
           product = first_digit + last_digit;
        }
        checksum += product;
        printf("%ld", temp);
        temp /= 100;
    }

    printf("%d", checksum);

    temp = cc_number;
    while (temp > 0)
    {
        long cur_num = temp % 10;
        checksum += (int)cur_num;
        temp /= 100;
    }

    printf("%d", checksum);

    if (checksum % 10 != 0)
    {
        printf("Invalid credit card number!");
    }

    int total_digits;
    temp = cc_number;
    while (temp != 0)
    {
        temp /= 10;
        total_digits++;
    }

    printf("%d", total_digits);

    temp = cc_number;
    long first_digit;
    while (temp >= 0)
    {
        first_digit = temp / 10;
        temp /= 10;
    }
    first_digit = (int)first_digit;

    //printf("%d", first_digit);

    temp = cc_number;
    long second_digit;
    while (temp > 0)
    {
        second_digit = temp / 10;
        temp /= 10;
    } 
    second_digit = (int)second_digit;
    //printf("%d", second_digit);


    int prefix_digits = concatenate(first_digit, second_digit);
    
    if ((total_digits == 15 && prefix_digits == 34) || prefix_digits == 37)
    {
        printf("Credit card is Amex\n");
    }

    if ((total_digits == 16 && prefix_digits == 51) || prefix_digits == 52 || prefix_digits == 53 || prefix_digits == 54 || prefix_digits == 55)
    {
        printf("Credit card is MasterCard\n");
    }

    if (total_digits == 13 || (total_digits == 16 && first_digit == 4))
    {
        printf("Credit card is Visa\n");
    }
}

