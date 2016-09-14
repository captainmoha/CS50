#include <stdio.h>
#include <cs50.h>
#include <math.h>

float getPosFloat(void);
int getNumCoins(float money);

int main(void)
{   
    printf("O hai! ");
    // get the amount of money
    float money = getPosFloat();
    
    // get numbers of coins
    int coins = getNumCoins(money);
    printf("%i\n", coins);
    return 0;
}

float getPosFloat(void)
{   
    // gets a positive float from the user
    float f = 0;
    do
    {   
        printf("How much change is owed?\n");
        f = GetFloat();
    }
    
    while (f < 0);
    
    return f;
}

int getNumCoins(float money)
{   
    // calculates the least number of coins
    
    // convert dollars to pennies
    float pen = round(money * 100);
    
    // case the pennis to an int
    int pennies = pen;
    // printf("money: %f\n", money);
    int coins = 0;
    
    // loop until the number of pennis is zero
    while (pennies > 0)
    {   
        if (pennies >= 25) 
        {
            pennies -= 25;
            coins++;
        }
        
        else if (pennies >= 10)
        {
            pennies -= 10;
            coins++;
        }
        
        else if (pennies >= 5)
        {
            pennies -= 5;
            coins++;
        }
        
        else 
        {
            coins++;
            pennies--;
        }
    }
    
    return coins;
}