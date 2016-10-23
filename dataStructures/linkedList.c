#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int val;
	struct node* next;
}	node;

node* createNode(int value);
void insertElement(node* head, int value);


int main(void)
{	

	node* head = createNode(1);
	
	for (int i = 0; i < 10; i++)
	{
		insertElement(head, i);
	}

	node* crawler = head;

	while (crawler != NULL)
	{
		printf("%d\n", crawler->val);
		crawler = crawler->next;
	}


	crawler = head;
	while (crawler != NULL)
	{
		free(crawler);
		crawler = crawler->next;
	}
	return 0;
}

node* createNode(int value)
{
	node* newNode = malloc(sizeof(node));
	newNode->val = value;
	newNode->next = NULL;

	return newNode;
}


void insertElement(node* head, int value)
{
	node* newNode = createNode(value);

	newNode->next = head->next;
	head->next = newNode;
}

