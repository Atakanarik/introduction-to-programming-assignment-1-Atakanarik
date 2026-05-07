#include <cs50.h>
#include <stdio.h>

/**
 * Assignment: Week 1 - Cash
 * Student: Atakanarik
 * Description: Calculates the minimum number of coins for change.
 */

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Get the number of cents owed
    int cents = get_cents();

    // Calculate quarters
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    // Calculate dimes
    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    // Calculate nickels
    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    // Calculate pennies
    int pennies = calculate_pennies(cents);

    // Print the total number of coins
    printf("%i\n", quarters + dimes + nickels + pennies);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    return cents / 25;
}

int calculate_dimes(int cents)
{
    return cents / 10;
}

int calculate_nickels(int cents)
{
    return cents / 5;
}

int calculate_pennies(int cents)
{
    return cents;
}
