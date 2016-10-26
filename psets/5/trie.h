// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// all english chars as well as the apostrophe '
#define ALPHABET_LENGTH 27

// trie structure
typedef struct trie {
	// pointers to subtrees
	struct trie* paths[ALPHABET_LENGTH];

	// flag to signal a word
	bool isWord;
}	trie;


/* Allocates and initializes a new trie and returns it */
trie* createTrie();

/* Clears a trie from memory recursively */
void clearTrie(trie* current);

/* Inserts a new word into the trie */
void insert(char* word);

/* Searches the trie for a word in O(k) where k is the length of the word */
bool find(const char* word);

/* Prints all words in the trie */
void printTrie(trie* current, char* word, int index);

/* Returns the trie size */
unsigned int getSize();

/* Contains the root trie */
trie* root;
/* Contains the trie size */
unsigned int trieSize;