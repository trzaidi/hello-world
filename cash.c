#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    //ASSIGN variables needed for monies;
    float dollars= 0.0;
    // PROMPT for change owed to customer but it cannot be negative (do while)
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    // CONVERT cents to coins
    int cents = round(dollars * 100);

    //COUNTER for coins by largest to smallest
    int coins = 0;
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    //PRINT coins owed from above
    printf("Coins owed: %i\n", coins);
}