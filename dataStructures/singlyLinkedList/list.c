#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

/*To be used as the head of the list*/
node* head = NULL;

/*keeps the size of the list*/
unsigned int size = 0;
node* createNode(char* value)
{	
	/*Creates a node on the heap and returns it*/

	node* newNode = malloc(sizeof(node));
	printf("val %s\n", value);
	strcpy(newNode->val, value);
	printf("newval %s\n", newNode->val);
	newNode->next = NULL;

	return newNode;
}


void insertElement(char* value)
{
	/*inserts an element to the list*/
	node* newNode = createNode(value);

	newNode->next = head->next;
	head->next = newNode;

	size++;
}

unsigned int getSize()
{	
	/* returns the size of the list*/
	return size;
}

void printList()
{	
	/*Prints the list as well as it's size*/
	node* crawler = head;

	printf("The list has %d elements\n", getSize());

	while (crawler != NULL)
	{
		printf("%s\n", crawler->val);
		crawler = crawler->next;
	}
}

void cleanList()
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