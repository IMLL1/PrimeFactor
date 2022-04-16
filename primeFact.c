#include <stdio.h>
#include <math.h>

int getNum(void);
int isPrime(int);
int lowestFact(int);
void printFactors(int);

int main(void)
{
    int num; // the number to factor

    num = getNum();
    printFactors(num);
    return 0;
}

/**
 * Prompts the user for a number to factor, and validates it
 *
 *  Inputs:
 * none
 *
 *  Output:
 * THe inputted number
 **/
int getNum(void)
{
    int num;

    do
    {
        printf("Enter a number to prime factorize -> ");
        scanf("%d", &num);
    } while (num <= 1);
}

/**
 * Checks if a given number is prime
 *
 *  Inputs:
 * num: the integer to check. Must be a positive.
 *
 *  Output:
 * Whether the given number is prime (boolean 0 or 1)
 **/
int isPrime(int num)
{
    int prime;   // whether the number is prime so far
    int idx = 2; // index to check divisibility

    prime = (num > 1) ? 1 : 0;
    while (idx <= sqrt(num) && prime)
    {
        if (!(num % idx))
        {
            prime = 0;
        }

        idx++;
    }
    return prime;
}

/**
 * Finds the lowest prime factor of a number
 *
 *  Inputs:
 * num: the integer to check. Must be a positive.
 *
 *  Output:
 * The lowest integer prime factor
 **/
int lowestFact(int num)
{
    int idx = 2; // index to check divisibility
    int lowest;  // the lowest prime factor

    lowest = 1;
    while (idx <= num && lowest == 1)
    {
        if (isPrime(idx) && !(num % idx))
        {
            lowest = idx;
        }

        idx++;
    }

    return lowest;
}

/**
 * Prints the prime factors of a number
 *
 *  Inputs:
 * num: the integer to factor
 *
 *  Output:
 * A printed list
 **/
void printFactors(int num)
{
    int numFct = num; // the number factored
    int factor;       // prime factor of the number

    if (isPrime(num))
    {
        printf("\n%d is prime, and cannot be factored\n", num);
    }
    else
    {
        printf("\nThe prime factors of %d are\n\t", num);
        while (numFct > 1)
        {
            factor = lowestFact(numFct);
            numFct /= factor;
            printf("%d ", factor);
        }
    }
}