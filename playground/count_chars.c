#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{   
    char* filename = argv[1];
    if (filename == NULL)
    {   
        printf("No input file passed! exiting.\n");
        return 1;
    }
    int count = 0;
    FILE* myfile = fopen(filename, "r");
    char c;
    
    while((c=fgetc(myfile)) != EOF)
    {
        count++;
    }
    fclose(myfile);
    printf("There are %i chars in the file\nSize of File is %ld\n", count, sizeof(myfile));
    
    return 0;
}