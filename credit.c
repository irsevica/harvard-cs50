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
    
    // Get product of numbers multiplied by two for checksum equation
    int checksum = 0;

    for (long temp = cc_number; temp > 0; temp /= 100)
    {
        long cur_num = (temp / 10) % 10;
        cur_num = (int)cur_num;
        int product = cur_num * 2;
        if (product >= 10)
        {
           int first_digit = product / 10;
           int last_digit = product % 10;
           product = first_digit + last_digit;
        }
        checksum += product;
    }

    // Add other numbers to checksum running total
    for (long temp = cc_number; temp > 0; temp /=100)
    {
        long cur_num = temp % 10;
        checksum += (int)cur_num;
    }

    if (checksum % 10 == 0)
    {
        // Get total digits of card num
        int total_digits = 0;
        for (long temp = cc_number; temp > 0; temp /= 10)
        {
            total_digits++;
        }
        
        // Get first digit of card num

        long first_digit;
        for (long temp = cc_number; temp > 0; temp /= 10 )
        {
            first_digit = temp % 10;
        }
        first_digit = (int)first_digit;

        // Get second digit of card num

        long second_digit;
        for (long temp = cc_number; temp > 0; temp /= 10 )
        {
            long test = temp / 100;
            if (test == 0)
            {
                second_digit = temp % 10;
                break;
            }
            second_digit = temp % 10;
        } 
        second_digit = (int)second_digit;

        // Concatenate first two digits
        int prefix_digits = concatenate(first_digit, second_digit);
        
        // Verify card type
        if ((total_digits == 15 && prefix_digits == 34) || prefix_digits == 37)
        {
            printf("Credit card is AMEX\n");
        }

        if ((total_digits == 16 && prefix_digits == 51) || prefix_digits == 52 || prefix_digits == 53 || prefix_digits == 54 || prefix_digits == 55)
        {
            printf("Credit card is MASTERCARD\n");
        }

        if (total_digits == 13 || (total_digits == 16 && first_digit == 4))
        {
            printf("Credit card is VISA\n");
        }
    }
    else
    {
        printf("INVALID CARD NUM\n");
    }
}

