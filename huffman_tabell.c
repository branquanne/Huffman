#include "huffman_tabell.h"
#include "bit_buffer.h"
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

// Function to traverse the Huffman Trie and create the Huffman Table sequence
void traverse_trie(TrieNode *node, bit_buffer *buffer, HuffmanTable *table, size_t *index) {

  // If the node is NULL, return
  if (node == NULL) {
    return;
  }

  // If the node is a leaf node, insert the character and bit sequence into the table
  if (node->left == NULL && node->right == NULL) {
    table->entries[*index].character = node->character;
    table->entries[*index].bit_sequence = bit_buffer_copy(buffer);
    (*index)++;
    return;
  }

  // Traverse the left node recursively
  bit_buffer_insert_bit(buffer, 0);
  traverse_trie(node->left, buffer, table, index);
  bit_buffer_remove_bit(buffer);

  // Traverse the right node recursively
  bit_buffer_insert_bit(buffer, 1);
  traverse_trie(node->right, buffer, table, index);
  bit_buffer_remove_bit(buffer);
}

// Function to create the Huffman Table
HuffmanTable *create_huffman_table(TrieNode *root, size_t num_characters) {

  // Allocate memory for the Huffman Table
  HuffmanTable *table = malloc(sizeof(HuffmanTable));
  table->entries = malloc(num_characters * sizeof(HuffmanTableEntry));
  table->size = num_characters;

  // Create a bit buffer
  bit_buffer *buffer = bit_buffer_empty();

  // Traverse the Huffman Trie and create the Huffman Table
  size_t index = 0;
  traverse_trie(root, buffer, table, &index);

  // Free the bit buffer
  bit_buffer_free(buffer);

  return table;
}
