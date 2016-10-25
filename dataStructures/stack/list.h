// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45


//  a node of a linked list
typedef struct node
{
	char val[LENGTH];
	struct node* next;
}	node;


/*Creates a node on the heap and returns it*/
node* createNode(char* value);

/*inserts an element to the list*/
void insertElement(char* value);

/* returns the size of the list*/
unsigned int getSize();

/*Prints the list as well as it's size*/
void printList();

/*Cleans the list from the memory*/
void cleanList();
/*To be used as the head of the list*/
node* head;

/*keeps the size of the list*/
unsigned int size;
