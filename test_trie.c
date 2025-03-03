#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

// Function to print the Huffman Trie
void printTrie(TrieNode *root, int depth) {
  if (root == NULL)
    return;

  for (int i = 0; i < depth; i++) {
    printf("  ");
  }

  if (root->character != '\0') {
    printf("'%c' (%d)\n", root->character, root->frequency);
  } else {
    printf("Internal (%d)\n", root->frequency);
  }

  printTrie(root->left, depth + 1);
  printTrie(root->right, depth + 1);
}

int main() {
  // Sample data
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int frequency[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data) / sizeof(data[0]);

  // Build Huffman Trie
  TrieNode *root = buildHuffmanTrie(data, frequency, size);

  // Print the Huffman Trie
  printf("Huffman Trie:\n");
  printTrie(root, 0);

  // Free the Huffman Trie
  freeTrie(root);

  return 0;
}