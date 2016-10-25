#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HashTable.h"
// table manibulation functions

int hash(char* word)
{	
	/* creates a hash for a given string */
	int hash = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		hash += (word[i] ^ 2);
	}

	return hash % TABLE_LENGTH;

}

void insert(int index, char* word)
{	
	/* inserts a word into the hash table */

	insertElement(word, hashTable[index]);
	listSizes[index]++;
}

bool find(char* word)
{	
	/* searches the table for a word */

	int hashVal = hash(word);
	node* list = hashTable[hashVal];
	
	return searchList(word, list);
}

void initTable()
{	
	/* allocates the table in memory */

	hashTable = malloc(sizeof(node*) * TABLE_LENGTH);

	for (int i = 0; i < TABLE_LENGTH; i++)
	{
		hashTable[i] = initList();
	}
}

void clearTable()
{	
	/* clear the table from memory */

	for (int i = 0; i < TABLE_LENGTH; i++)
	{
		cleanList(hashTable[i]);
	}

	free(hashTable);
}


// list manibulation functions


/*keeps the size of the table*/
unsigned int tableSize;
unsigned int listSizes[TABLE_LENGTH];

node* createNode(char* value)
{	
	/*Creates a node on the heap and returns it*/

	node* newNode = malloc(sizeof(node));
	// printf("val %s\n", value);
	strcpy(newNode->val, value);
	// printf("newval %s\n", newNode->val);
	newNode->next = NULL;

	return newNode;
}

node* initList()
{	
	/* Initializes the first node of the list */

	node* newNode = malloc(sizeof(node));
	strcpy(newNode->val, "");
	newNode->next = NULL;
}

void insertElement(char* value, node* head)
{
	/*inserts an element to the list*/
	node* newNode = createNode(value);

	newNode->next = head->next;
	head->next = newNode;

	tableSize++;
}

unsigned int getTableSize()
{	
	/* returns the size of the list*/
	return tableSize;
}

void printList(node* head)
{	
	/*Prints the list as well as it's size*/
	node* crawler = head;

	printf("The Table has %d elements\n", getTableSize());

	while (crawler != NULL)
	{
		printf("%s\n", crawler->val);
		crawler = crawler->next;
	}
}

void cleanList(node* head)
{	
	/*Cleans the list from the memory*/
	node* crawler = head;
	while (head != NULL)
	{	
		crawler = head;
		head = head->next;
		free(crawler);
	}
}

bool searchList(char* word, node* head)
{	
	/* search a list for an element */
	
	node* crawler = head;

	while (crawler != NULL)
	{
		if (strcmp(crawler->val, word) == 0)
		{
			return true;
		}
		crawler = crawler->next;
	}

	return false;
}