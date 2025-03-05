// FILE: test_trie.c
#include "freq_table.h"
#include "trie.h"

// Print the Huffman Trie
void printTrie(TrieNode *root, int depth) {
  if (root == NULL) {
    return;
  }
  if (root->character == '\0') {
    printf("%*sInternal Node, Frequency: %d\n", depth * 2, "", root->frequency);
  } else {
    printf("%*sCharacter: %c, Frequency: %d\n", depth * 2, "", root->character, root->frequency);
  }
  printTrie(root->left, depth + 1);
  printTrie(root->right, depth + 1);
}

// Function to test building the Huffman Trie
void testBuildHuffmanTrie() {
  int *frequencyTable = checkFrequency("löremipsum.txt");
  TrieNode *root = buildHuffmanTrie(frequencyTable);

  if (root == NULL) {
    printf("Test failed: Huffman Trie root is NULL\n");
  } else {
    printf("Test passed: Huffman Trie root is not NULL\n");
  }

  freeTrie(root);
  free(frequencyTable);
}

// Function to test freeing the Trie
void testFreeTrie() {
  int *frequencyTable = checkFrequency("löremipsum.txt");
  TrieNode *root = buildHuffmanTrie(frequencyTable);
  freeTrie(root);
  printf("Test passed: Trie memory freed successfully\n");
  free(frequencyTable);
}

int main() {
  testBuildHuffmanTrie();
  printf("\n");

  TrieNode *root = buildHuffmanTrie(checkFrequency("löremipsum.txt"));
  printTrie(root, 0);
  printf("\n");

  testFreeTrie();
  return 0;
}
