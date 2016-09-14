/**
 * fixed1.c
 *
 * Doug Lloyd
 * lloyd@cs50.harvard.edu
 *
 * A buggy program... now repaired
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    
    if (strcmp("", argv[1]))
    {
        printf("You figured it out!\n");
    }
    else
    {
        printf("Sorry :-(\n");
    }
}