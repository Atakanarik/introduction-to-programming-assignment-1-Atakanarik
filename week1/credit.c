#include <cs50.h>
#include <stdio.h>

/**
 * Assignment: Week 1 - Credit
 * Student: Atakanarik
 * Description: Validates credit card numbers using Luhn's Algorithm.
 */

int main(void)
{
    // Get user input
    long number = get_long("Number: ");

    int sum = 0;
    int length = 0;
    long temp = number;
    long start_digits = number;

    // Apply Luhn's Algorithm to check checksum
    while (temp > 0)
    {
        int digit = temp % 10;
        if (length % 2 == 1)
        {
            int product = digit * 2;
            sum += (product % 10) + (product / 10);
        }
        else
        {
            sum += digit;
        }
        temp /= 10;
        length++;
    }

    // Determine the first two digits for card type
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    // Final check for validity and brand identification
    if (sum % 10 == 0)
    {
        // AMEX: 15 digits, starts with 34 or 37
        if ((start_digits == 34 || start_digits == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        // MASTERCARD: 16 digits, starts with 51, 52, 53, 54, or 55
        else if ((start_digits >= 51 && start_digits <= 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        // VISA: 13 or 16 digits, starts with 4
        else if ((start_digits / 10 == 4) && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
