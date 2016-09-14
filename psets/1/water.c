#include <stdio.h>
#include <cs50.h>

#define OUNCES_PER_MINUTE 192
#define BOTTLE_CAPACITY 16

int main(void)
{   
    printf("minutes: ");
    // get the number of minutes spent in the shower
    int minutes = GetInt();
    // calculate the equivilant number of bottles
    int bottles = minutes * (OUNCES_PER_MINUTE / BOTTLE_CAPACITY);
    
    printf("bottles: %i\n", bottles);
    
}