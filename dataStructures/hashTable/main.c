#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HashTable.h"

int main(void)
{
	// testing the table
	initTable();

	/*char* strings[] = {"array", "linkedList", "stack", "queue", "hashtable", "moha", "haha", "oh", "yeah"};

	for (int i = 0; i < 9; ++i)
	{
		printf("%s has a hash of %d\n", strings[i], hash(strings[i]));
		insert(hash(strings[i]), strings[i]);

	}
	printf("Table has %d elements\n", tableSize);

	for (int i = 0; i < 9; ++i)
	{
		bool isFound = find(strings[i]);
		printf("%s yields %s\n", strings[i], isFound ? "true" : "false");

	}

	bool isFound = find("yeah baby!");
		printf("yeah baby! yields %s\n", isFound ? "true" : "false");*/

	FILE* dictFile = fopen("large", "r");

	if (dictFile != NULL)
	{
		char word[LENGTH];
		while (fscanf(dictFile, "%s", word) == 1)
		{	
			printf("%s\n", word);
			insert(hash(word), word);
		}
		fclose(dictFile);
	}
	
	for (int i = 0; i < TABLE_LENGTH; ++i)
	{
		printf("list #%d has %d elements.\n", i+1, listSizes[i]);
	}
	clearTable();
	return 0;
}