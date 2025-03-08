#ifndef TRIE_H
#define TRIE_H

#include "freq_table.h"

// Define the Node structure
typedef struct Node {
	char data;
	unsigned freq;
	struct Node *left, *right;
  } Node;

// Function to create a new node
Node *create_node(char data, unsigned freq);

// Function to build the Huffman tree
Node *build_huffman_tree(int *freq);

#endif // TRIE_H