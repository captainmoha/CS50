#include <stdio.h>
#include <stdlib.h>

#include "list.h"

char* toString(int x);
int main(void)
{	

	char* str = toString(1);
	printf("tostr: %s", str);
	
	head = createNode(str);
	free(str);
	
	for (int i = 0; i < 10; i++)
	{	
		str = toString(i);
		insertElement(str);
		free(str);
	}


	printList();

	cleanList();

	return 0;
}

char* toString(int x)
{
	char* str = malloc(sizeof(char) * 10 + 1);

	int index = 0;

	while (x != 0)
	{
		str[index] = x + '0';
		index++;
		x /= 10;
	}

	str[index] = '\0';

	return str;
}
