#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(char* element);
void pop();
char* top();

int main(void)
{	
	char* strings[] = {"array", "linkedList", "stack", "queue", "hashtable"};

	pop();
	for (int i = 0; i < 5; i++)
	{
		push(strings[i]);
	}
	
	printList();
	top();
	pop();
	printList();
	top();
	pop();
	printList();

	cleanList();
}

void push(char* element)
{	

	/*
		Pushes an element into the list
	*/

	if (head == NULL)
	{
		head = createNode(element);
	}
	
	else
	{	
		node* newNode = createNode(element);
		// printf("createdNode\n");
		newNode->next = head;
		head = newNode;

		// printf("last\n");
	}
	
	size++;

}

void pop()
{
	/*
		removes the last added element to the stack
	*/

	node* poppedNode = head;
	char* poppedStr = head->val;

	if (head == NULL)
	{
		printf("Cannot pop. Stack is empty!\n");
	}

	else
	{	
		head = head->next;
		printf("Popped %s off the stack.\n", poppedStr);
		free(poppedNode);
		
		size--;
	}

}

char* top()
{	
	/* 
		returns the last added item to the stack (LIFO)
	*/

	printf("The top of the stack is: %s.\n", head->val);
	return head->val;
}



