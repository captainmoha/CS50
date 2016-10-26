#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "trie.h"

unsigned int size = 0;

trie* createTrie()
{
	/* Allocates and initializes a new trie and returns it */

	trie* newTrie = malloc(sizeof(trie));
	// newTrie->paths = malloc(sizeof(trie) * 26);
	for (int i = 0; i < ALPHABET_LENGTH; i++)
	{
		newTrie->paths[i] = NULL;
	}

	newTrie->isWord = false;

	return newTrie;
}

void insert(char* word)
{	
	/* Inserts a new word into the trie */

	int i, len, path;
	trie* crawler = root;
	for (i = 0, len = strlen(word); i < len; i++)
	{	
		path = (isalpha(word[i])) ? tolower(word[i]) - 'a' : ALPHABET_LENGTH - 1;
		if (crawler->paths[path] == NULL)
		{
			crawler->paths[path] = createTrie();
		}

		crawler = crawler->paths[path];
	}

	crawler->isWord = true;
	size++;
}

bool find(char* word)
{	
	/* Searches the trie for a word in O(k) where k is the length of the word */

	trie* crawler = root;
	for (int i = 0; i < strlen(word); ++i)
	{	
		int path = (isalpha(word[i])) ? tolower(word[i]) - 'a' : ALPHABET_LENGTH - 1;
		printf("path is %d : %c\n", path, path+'a');
		if (crawler->paths[path] == NULL)
		{
			return false;
		}

		crawler = crawler->paths[path];
	}

	return (crawler->isWord);
}

void printTrie(trie* current, char* word, int index)
{	
	/* Prints all words in the trie */

	if (current->isWord)
	{
		printf("%s\n", word);
	}

	word[index + 1] = '\0';

	for (int i = 0; i < ALPHABET_LENGTH; ++i)
	{
		trie* child = current->paths[i];

		if (child != NULL)
		{
			
			word[index] = (i != 26) ? i + 'a' : '\'';

			printTrie(child, word, index + 1);
		}
	}

	word[index] = '\0';
}

unsigned int getSize()
{	
	/* Returns the trie size */

	return size;
}

void clearTrie(trie* current)
{	
	/* Clears a trie from memory recursively */

	for (int i = 0; i < ALPHABET_LENGTH; i++)
	{	
		if (current->paths[i] != NULL)
		{
			clearTrie(current->paths[i]);
		}
	}
	
	free(current);
}