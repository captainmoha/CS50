#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(char* element);
void pop();
char* front();

int main(void)
{	
	char* strings[] = {"array", "linkedList", "stack", "queue", "hashtable"};

	pop();

	for (int i = 0; i < 5; i++)
	{
		push(strings[i]);
	}
	
	printList();
	front();
	pop();
	printList();

	printf("front is %s\n", front());
	cleanList();

}

void push(char* element)
{	

	/*
		Pushes an element into the queue
	*/

	if (head == NULL)
	{
		head = createNode(element);
	}
	
	else
	{	
		node* newNode = createNode(element);
		// printf("createdNode\n");
		node* crawler = head;

		while (crawler->next != NULL)
		{
			crawler = crawler->next;
		}

		crawler->next = newNode;
		// printf("last\n");
	}
	
	size++;

}

void pop()
{
	/*
		removes the last added element to the queue
	*/

	node* poppedNode = head;
	char* poppedStr = head->val;

	if (head == NULL)
	{
		printf("Cannot pop. queue is empty!\n");
	}

	else
	{	
		head = head->next;
		printf("Popped %s off the queue.\n", poppedStr);
		free(poppedNode);
		
		size--;
	}

}

char* front()
{	
	/* 
		returns the last added item to the queue (FIFO)
	*/

	if (head == NULL)
	{
		printf("Queue is empty!\n");
		return "";
	}

	printf("The front of the queue is: %s.\n", head->val);
	return head->val;
}



