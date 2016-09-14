/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int low = 0;
    int high = n - 1;
    // printf("Size: %i\n", n);
    while(low <= high)
    {   
        
        int mid = low + (high - low) / 2;
        
        // printf("%i\n", values[mid]);
        if (values[mid] == value)
        {
            return true;
        }
        
        else if (values[mid] > value)
        {   
            // printf("value is smaller: %i\n", values[mid]);
            high = mid - 1;
        }
        
        else if (values[mid] < value)
        {   
            // printf("value is bigger: %i\n", values[mid]);
            low = mid + 1;
        }
    }
    
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implement insertion sort
    for (int i = 1; i < n; i++)
    {
        int usorted_indx = i;
        int current = values[i];
        
        // as long as the current value is smaller than the previous one
        // shift the elements to the right
        while(usorted_indx > 0 && (current < values[usorted_indx - 1]))
        {
            // shift
            values[usorted_indx] = values[usorted_indx - 1];
            usorted_indx--;
        }
        values[usorted_indx] = current;
    }
    
    return;
}