#include "huffman.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc test_trie.c trie.c -o test_trie

void print_node(Node *node, int depth) {
  if (node == NULL)
    return;

  for (int i = 0; i < depth; i++)
    printf("  ");

  if (node->left == NULL && node->right == NULL) {
    printf("Leaf: '%c' (freq: %d)\n", node->data, node->freq);
  } else {
    printf("Internal (freq: %d)\n", node->freq);
    print_node(node->left, depth + 1);
    print_node(node->right, depth + 1);
  }
}

int main() {
  printf("=== Testing Huffman tree operations ===\n");

  // Create a sample frequency table
  int *freq = calloc(ASCII_SIZE, sizeof(int));
  freq['a'] = 5;
  freq['b'] = 2;
  freq['c'] = 1;
  freq['d'] = 3;

  // Build the Huffman tree
  Node *root = build_huffman_tree(freq);
  if (!root) {
    printf("Error: build_huffman_tree returned NULL\n");
    free(freq);
    return 1;
  }

  printf("Huffman Tree Structure:\n");
  print_node(root, 0);

  // Generate and test Huffman codes
  char *codes[ASCII_SIZE] = {0};
  char code[ASCII_SIZE] = {0};
  generate_huffman_codes(root, code, 0, codes);

  printf("\nGenerated Huffman Codes:\n");
  printf("'a': %s\n", codes['a'] ? codes['a'] : "NULL");
  printf("'b': %s\n", codes['b'] ? codes['b'] : "NULL");
  printf("'c': %s\n", codes['c'] ? codes['c'] : "NULL");
  printf("'d': %s\n", codes['d'] ? codes['d'] : "NULL");

  // Cleanup
  free(freq);
  for (int i = 0; i < ASCII_SIZE; i++) {
    free(codes[i]);
  }
  free_huffman_tree(root);

  printf("=== Huffman tree tests complete ===\n");

  return 0;
}