

typedef struct TrieNode {
  int frequency;
  char character;
  struct TrieNode *left;
  struct TrieNode *right;
} TrieNode;

int compareValues(void *val1, void *val2);

TrieNode *createNode(char character, int frequency);

TrieNode *buildHuffmanTrie(int *frequencyTable);

void freeTrie(TrieNode *root);
