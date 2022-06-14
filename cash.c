#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int get_cents(void)
{
    int amount;
    do
    {
        amount = get_int("How Many Cents? ");
        if (amount >= 0)
        {
            break;
        }
    } while (amount <= 0);

    return amount;
}

int calculate_quarters(int amount)
{
    int quarter = 25;
    int total_quarters = amount/quarter;
    if (amount >= quarter)
    {
        printf("Total Quarters: %i\n", total_quarters);
    }
    return total_quarters;
}

int calculate_dimes(int amount)
{
    int dime = 10;
    int total_dimes = amount/dime;

    if (amount >= dime)
    {
        printf("Total Dimes: %i\n",total_dimes);
    }
    return total_dimes;
}

int calculate_nickels(int cents)
{
    int nickel = 5;
    int total_nickel = cents / nickel;

    if (cents >= nickel)
    {
        {
            printf("Total Nickels: %i\n", total_nickel);
        }
    }
    return total_nickel;
}

int calculate_pennies(int amount)
{
    int penny = 1;
    int total_pennies =  amount / penny;

    if (amount >= penny)
    {
        printf("Total Pennies: %i\n", total_pennies);
    }
    return total_pennies;
}
int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}