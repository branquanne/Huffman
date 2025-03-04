#include "trie.h"
#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

// Comparator using pqueue.h pqueue_cmp_func
int compareValues(void *val1, void *val2) {
  TrieNode *node1 = (TrieNode *)val1;
  TrieNode *node2 = (TrieNode *)val2;
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
  for (int i = 0; i < 256; i++) {
    if (frequencyTable[i] >= 0) {
      TrieNode *node = createNode((unsigned char)i, frequencyTable[i]);
      pqueue_insert(pq, node);
    }
  }

  //  Build the Huffman Trie
  while (pqueue_is_empty(pq) == 0) {
    TrieNode *left = (TrieNode *)pqueue_inspect_first(pq);
    pqueue_delete_first(pq);
    if (pqueue_is_empty(pq)) {
      pqueue_insert(pq, left);
      break;
    }
    TrieNode *right = (TrieNode *)pqueue_inspect_first(pq);
    pqueue_delete_first(pq);

    TrieNode *internalNode = createNode('\0', left->frequency + right->frequency);
    internalNode->left = left;
    internalNode->right = right;

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
