// list related data

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

//  a node of a linked list
typedef struct node
{
	char val[LENGTH];
	struct node* next;
}	node;

/* Initialized the first node of the list */
node* initList();

/* Creates a node on the heap and returns it */
node* createNode(char* value);

/* inserts an element to the list */
void insertElement(char* value, node* head);

/* returns the size of the list */
unsigned int getTableSize();

/* search a list for an element */
bool searchList(char* word, node* head);

/*Prints the list as well as it's size*/
void printList(node* head);

/* Cleans the list from the memory */
void cleanList(node* head);

// table related data

// size of table elements (lists)
#define TABLE_LENGTH 26

/* allocates the table in memory */
void initTable();

/* clear the table from memory */
void clearTable();

/* creates a hash for a given string */
int hash(char* word);

/* inserts a word into the hash table */
void insert(int index, char* word);

/* searches the table for a word */
bool find(char* word);


// holds the table which is a list of pointers to linkedLists
node** hashTable;

// keeps the sizes of all lists in the table
unsigned int listSizes[TABLE_LENGTH];
// keeps the size of the table
unsigned int tableSize;