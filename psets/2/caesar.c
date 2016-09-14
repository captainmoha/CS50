#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

#define ALPHABET_COUNT 26

string encrypt(string text, int key);
bool valid_key(string key);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Include the key as a command-line argument!\n");
        return 1;
    }
    
    string text;
    if (valid_key(argv[1]))
    {   
        int key = atoi(argv[1]);
        text = GetString();
        string cypher = encrypt(text, key);

        printf("%s\n", cypher);
        free(cypher);
    }
    
    return 0;
}

string encrypt(string text, int key)
{   
    /*
        encrypts and returns a string using the key as a shift value
    */
    
    // printf("inputs: text=%s , key=%i\n", text, key);
    string cypher = malloc(strlen(text) * sizeof(char));
    
    for (int i = 0; i < strlen(text); i++)
    {   
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {   
                // printf("lower, %c\n", text[i]);
                
                // subtract 'a' to make counting start from 0
                // then add it again when encrypting
                cypher[i] = (text[i] - 'a' + key) % ALPHABET_COUNT + 'a';
            }
            else
            {
                cypher[i] = (text[i] - 'A' + key) % ALPHABET_COUNT + 'A';
            }
           
        }
        else
        {
            cypher[i] = text[i];
        }
    }
    
    return cypher;
}

bool valid_key(string key)
{   
    /*
        takes a key as a string and makes sure it's all digits
    */
    
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    
    return true;
}

