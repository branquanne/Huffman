#include "trie.h"
#include "huffman.h"
#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * File: trie.c
 *
 * Description: This file contains functions for creating and managing nodes
 *              in a Huffman tree. The tree is built using a priority queue.
 *              The nodes are used to generate Huffman codes for encoding and
 *              decoding files. 
 * 
 * Author: Henrik Röjvall & Bran Quanne
 * 
 * Date: 2025-03-08
 * 
 */

/* External functions */

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

Node *build_huffman_tree(int *freq) {
  pqueue *pq = pqueue_empty(node_cmp);
  int pqueue_count = 0; 

  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (freq[i]) {
      pqueue_insert(pq, create_node((char)i, freq[i]));
      pqueue_count++; 
    }
  }

  if (pqueue_count == 0) {
    pqueue_insert(pq, create_node('\0', 1));
    pqueue_count++;
  }

  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (freq[i] == 0) {
      pqueue_insert(pq, create_node((char)i, 0));
      pqueue_count++; 
    }
  }

  while (pqueue_count > 1) { 
    Node *left = pqueue_inspect_first(pq);
    pqueue_delete_first(pq);
    pqueue_count--; 

    Node *right = pqueue_inspect_first(pq);
    pqueue_delete_first(pq);
    pqueue_count--; 

    Node *top = create_node('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    pqueue_insert(pq, top);
    pqueue_count++; 
  }

  Node *root = pqueue_inspect_first(pq);
  pqueue_kill(pq);

  return root;
}

void free_huffman_tree(Node *root) {
  if (root == NULL) {
    return;
  }

  free_huffman_tree(root->left);
  free_huffman_tree(root->right);
  free(root);
}