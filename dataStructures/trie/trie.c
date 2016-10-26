#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define ALPHABET_LENGTH 26

// trie structure
typedef struct trie {
	struct trie* paths[ALPHABET_LENGTH];
	bool isWord;
}	trie;

trie* createTrie();
void clearTrie(trie* current);
void insert(char* word);
bool find(char* word);
void printTrie(trie* current, char* word);
unsigned int getSize();

trie* root;
unsigned int size = 0;

int main(void)
{	
	root = createTrie();
	/*char* strings[] = {"array", "link", "linkedlist", "stack", "queue", "hashtable", "moha", "haha", "oh", "yeah"};

	for (int i = 0; i < 6; ++i)
	{
		insert(strings[i]);
	}

	for (int i = 0; i < 9; ++i)
	{
		bool isFound = find(strings[i]);
		printf("%s yields %s\n", strings[i], isFound ? "true" : "false");

	}*/

	FILE* dictFile = fopen("large", "r");

	if (dictFile != NULL)
	{
		char word[LENGTH];
		while (fscanf(dictFile, "%s", word) == 1)
		{	
			printf("%s\n", word);
			insert(word);
		}
		fclose(dictFile);
	}

	printf("Just read %d words!\n", getSize());
	char wordTemp[LENGTH];
	strcpy(wordTemp, "");

	// printTrie(root, wordTemp);
	clearTrie(root);
	return 0;
}

trie* createTrie()
{
	trie* newTrie = malloc(sizeof(trie));

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
		path = tolower(word[i]) - 'a';
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
		int path = tolower(word[i]) - 'a';
		printf("path is %d : %c\n", path, path+'a');
		if (crawler->paths[path] == NULL)
		{
			return false;
		}

		crawler = crawler->paths[path];
	}

	return (crawler->isWord);
}

void printTrie(trie* current, char* word)
{	
	// printf("Func: %s\n", word);

	for (int i = 0; i < ALPHABET_LENGTH; i++)
	{	
		// printf("Lop: %s\n", word);
		if (current->paths[i] != NULL)
		{	

			if (current->isWord)
			{	
				printf("word: %s\n", word);
			}

			char buffer[2];
			buffer[0] = i + 'a';
			buffer[1] = '\0';
			// printf("k:%s\n", word);
			strcat(word, buffer);
			
			printTrie(current->paths[i], word);
		}			
	}

	if (current->isWord && strlen(word) > 0)
	{	
		printf("word: %s\n", word);
		strcpy(word, "");
	}
}

unsigned int getSize()
{	
	return size;
}

void clearTrie(trie* current)
{
	for (int i = 0; i < 26; i++)
	{	
		if (current->paths[i] != NULL)
		{
			clearTrie(current->paths[i]);
		}
	}
	
	free(current);
}

