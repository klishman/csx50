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

int calculate_coins(int amount, char* label, int divisor)
{

    int total = amount/divisor;
    if (amount >= divisor)
    {
        printf("Total %s: %i\n", label,total);
    }
    return total;
}

int calculate_quarters(int amount)
{
    return calculate_coins(amount,"Quarter",25);
}

int calculate_dimes(int amount)

{
    return calculate_coins(amount,"Dime",10);
}

int calculate_nickels(int amount)
{
    return calculate_coins(amount,"Nickel",5);
}

int calculate_pennies(int amount)
{
    return calculate_coins(amount,"Penny",1);
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
