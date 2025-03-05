#include "trie.h"
#include "pqueue.h"

// Comparator using pqueue.h pqueue_cmp_func
int compareValues(void *val1, void *val2) {

  // Cast the void pointers to TrieNode pointers
  TrieNode *node1 = (TrieNode *)val1;
  TrieNode *node2 = (TrieNode *)val2;

  // Return the difference between the frequencies
  return node1->frequency - node2->frequency;
}

// Create a new Trie node
TrieNode *createNode(char character, int frequency) {
  TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
  node->character = character;
  node->frequency = frequency;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Build Huffman Trie
TrieNode *buildHuffmanTrie(int *frequencyTable) {
  pqueue *pq = pqueue_empty(compareValues);

  // Create leaf nodes and insert them into the priority queue
  for (int i = 0; i < MAX_ASCII_SIZE; i++) {
    if (frequencyTable[i] >= 0) {

      // Create a new node with the index as the character and the frequency from the frequency table
      TrieNode *node = createNode((unsigned char)i, frequencyTable[i]);
      pqueue_insert(pq, node);
    }
  }

  //  Build the Huffman Trie
  while (pqueue_is_empty(pq) == false) {

    // If there is only one node left in the priority queue, break
    TrieNode *left = (TrieNode *)pqueue_inspect_first(pq);
    pqueue_delete_first(pq);

    // If the priority queue is empty, insert the last node
    if (pqueue_is_empty(pq)) {
      pqueue_insert(pq, left);
      break;
    }
    TrieNode *right = (TrieNode *)pqueue_inspect_first(pq);
    pqueue_delete_first(pq);

    // Create an internal node
    TrieNode *internalNode = createNode('\0', left->frequency + right->frequency);
    internalNode->left = left;
    internalNode->right = right;

    // Insert the internal node into the priority queue
    pqueue_insert(pq, internalNode);
  }

  TrieNode *root = (TrieNode *)pqueue_inspect_first(pq);
  pqueue_delete_first(pq);
  pqueue_kill(pq);
  return root;
}

// Free memory for trie
void freeTrie(TrieNode *root) {
  if (root == NULL)
    return;
  freeTrie(root->left);
  freeTrie(root->right);
  free(root);
}
