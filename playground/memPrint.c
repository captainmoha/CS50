#include <stdio.h>

int main(void)
{   
    
    long long arr[10];
    
    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", arr + i);
    }
    return 0;
}