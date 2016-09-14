#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

string getInitials(string name);

int main(void)
{   
    // get string from user
    string name = GetString();
    
    // get initals
    string initials = getInitials(name);
    
    printf("%s\n", initials);
    free(initials);
    return 0;
}

string getInitials(string name)
{
    /*
        goes through a name and returns its initials in uppercase
    */
    
    string initials = malloc(sizeof(char));
    
    for (int i = 0; i < strlen(name); i++)
    {   
        char temp_char;
        if (i == 0)
        {
            temp_char = toupper(name[i]);
            // printf("C at first: %temp_char\n", temp_char);
            strncat(initials, &temp_char, 1);
        }
        
        else if (name[i] == ' ')
        {   
            temp_char = toupper(name[i + 1]);
            // printf("C in loop: %temp_char\n", temp_char);
            strncat(initials, &temp_char, 1);
        }
        
    }

    return initials;
}