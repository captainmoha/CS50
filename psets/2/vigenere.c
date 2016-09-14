#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

#define ALPHABET_COUNT 26

string encrypt(string text, string key);
bool valid_key(string key);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Include the key as a command-line argument!\n");
        return 1;
    }
    
    
    if (!valid_key(argv[1]))
    {   
        printf("Key must be made of only alphebetical charchaters!\n");
        return 1;
    }
    
    else
    {
        string keyword = argv[1];
        string text = GetString();
        string cypher = encrypt(text, keyword);

        printf("%s\n", cypher);
        free(cypher);
    }
    
    return 0;
}

string encrypt(string text, string keyword)
{   
    /*
        encrypts and returns a string using the key as a shift value
    */
    
    // printf("inputs: text=%s , key=%i\n", text, key);
    string cypher = malloc(strlen(text) * sizeof(char));
    int key_index = 0;
    int len_keyword = strlen(keyword);
    
    for (int i = 0; i < strlen(text); i++)
    {   
        if (isalpha(text[i]))
        {   
            char key = keyword[key_index % len_keyword];
            
            // how much to subtract depending on case of a char in a keyword
            char offset = isupper(key) ? 'A' : 'a';
            
            // printf("Key is %c\n", key);
            
            if (islower(text[i]))
            {   
                // printf("lower, %c\n", text[i]);
                
                // subtract 'a' to make counting start from 0 
                // then add it again when encrypting
                cypher[i] = (text[i] - 'a' + key - offset) % ALPHABET_COUNT + 'a';
            }
            else
            {
                // printf("upper, %c\n", text[i]);
                cypher[i] = (text[i] - 'A' + key - offset) % ALPHABET_COUNT + 'A';
            }
            key_index++;
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
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    
    return true;
}

