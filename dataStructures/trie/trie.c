#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define ALPHABET_LENGTH 27

// trie structure
typedef struct trie {
	struct trie* paths[ALPHABET_LENGTH];
	bool isWord;
}	trie;

trie* createTrie();
void clearTrie(trie* current);
void insert(char* word);
bool find(char* word);
void printTrie(trie* current, char* word, int index);
unsigned int getSize();

trie* root;
unsigned int size = 0;

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

trie* createTrie()
{
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
	return size;
}

void clearTrie(trie* current)
{
	for (int i = 0; i < ALPHABET_LENGTH; i++)
	{	
		if (current->paths[i] != NULL)
		{
			clearTrie(current->paths[i]);
		}
	}
	
	free(current);
}