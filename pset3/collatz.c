#include <stdio.h>

int collatz(int n);

int main(void)
{
    int invalid_input;
    int n;
    do 
    {
        invalid_input = 0;
        printf("Please input an integer value: ");
        int result = scanf("%d", &n);
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
            printf("You entered: %d\n", n);
        }
    }
    while (invalid_input == 1);

   int result = collatz(n);
   printf("Took %d steps.\n", result);
}

int collatz(int n)
{
    int steps = 0;
    // base case
    if (n == 1)
        return steps;
    // recursion case
    else if (n % 2 == 0)
    {
        steps++;
        return steps + collatz(n/2);
    }
    else
    {
        steps++;
        return steps + collatz(3*n + 1);
    }
}