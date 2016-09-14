#include <stdio.h>
#include <cs50.h>

int getPosInt(void);
void drawPyramid(int height);

int main(void)
{   
    
    int height = getPosInt();
    drawPyramid(height);
   
    return 0;
}

int getPosInt(void)
{
    // gets a positive integer from the user
    int n = 0;
    
    do
    {   
        // prompt user for input 
        printf("height: ");
        n = GetInt();
    }
    
    while (n < 0 || n > 23);
    
    return n;
}

void drawPyramid(int height)
{
    /*
        draws mario's pyramid
    */
    
    for (int i = 0; i < height; i++)
    {   
        int j;
        
        // print the spaces
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        
        // print the hashes
        for (int k = 0; k < height - j + 1; k++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}