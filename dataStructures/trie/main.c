#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "trie.h"

int main(void)
{	
	root = createTrie();
	/*char* strings[] = {"array", "link", "linkedlist", "stack's", "queue", "hashtable", "moha", "haha", "oh", "yeah", "arg"};

	for (int i = 0; i < 11; ++i)
	{
		insert(strings[i]);
	}

	for (int i = 0; i < 9; ++i)
	{
		bool isFound = find(strings[i]);
		printf("%s yields %s\n", strings[i], isFound ? "true" : "false");

	}
*/
	FILE* dictFile = fopen("large", "r");

	if (dictFile != NULL)
	{
		char word[LENGTH];
		while (fscanf(dictFile, "%s", word) == 1)
		{	
			// printf("%s\n", word);
			insert(word);
		}
		fclose(dictFile);
	}

	printf("Just read %d words!\n", getSize());
	char wordTemp[LENGTH];
	strcpy(wordTemp, "");

	printTrie(root, wordTemp, 0);
	clearTrie(root);
	return 0;
}