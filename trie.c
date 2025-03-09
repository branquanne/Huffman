#include "trie.h"
#include "huffman.h"
#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node
Node *create_node(char data, int freq) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "Error: Cannot allocate memory\n");
    exit(1);
  }

  node->data = data;
  node->freq = freq;
  node->left = node->right = NULL;

  return node;
}

// Function to build the Huffman tree
Node *build_huffman_tree(int *freq) {
  pqueue *pq = pqueue_empty(node_cmp);
  int pqueue_count = 0; // Initialize a counter for the priority queue size

  // First, add all characters with non-zero frequency
  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (freq[i]) {
      pqueue_insert(pq, create_node((char)i, freq[i]));
      pqueue_count++; // Increment the counter when inserting a node
    }
  }

  // If no characters were added (empty file), add at least one
  if (pqueue_count == 0) {
    pqueue_insert(pq, create_node('\0', 1));
    pqueue_count++;
  }

  // Add characters with zero frequency, giving them a very small frequency (1)
  // to ensure they get included in the tree
  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (freq[i] == 0) {
      pqueue_insert(pq, create_node((char)i, 0));
      pqueue_count++; // Increment the counter when inserting a node
    }
  }

  while (pqueue_count > 1) { // Use the counter instead of pqueue_size
    Node *left = pqueue_inspect_first(pq);
    pqueue_delete_first(pq);
    pqueue_count--; // Decrement the counter when deleting a node

    Node *right = pqueue_inspect_first(pq);
    pqueue_delete_first(pq);
    pqueue_count--; // Decrement the counter when deleting a node

    Node *top = create_node('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    pqueue_insert(pq, top);
    pqueue_count++; // Increment the counter when inserting a node
  }

  Node *root = pqueue_inspect_first(pq);
  pqueue_kill(pq);

  return root;
}

// Function to free the memory allocated for the Huffman tree
void free_huffman_tree(Node *root) {
  if (root == NULL) {
    return;
  }

  free_huffman_tree(root->left);
  free_huffman_tree(root->right);
  free(root);
}