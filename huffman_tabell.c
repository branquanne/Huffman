#include "huffman_tabell.h"
#include "bit_buffer.h"
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

void traverse_trie(TrieNode *node, bit_buffer *buffer, HuffmanTable *table, size_t *index) {
  if (node == NULL) {
    return;
  }

  if (node->left == NULL && node->right == NULL) {
    table->entries[*index].character = node->character;
    table->entries[*index].bit_sequence = bit_buffer_copy(buffer);
    (*index)++;
    return;
  }

  bit_buffer_insert_bit(buffer, 0);
  traverse_trie(node->left, buffer, table, index);
  bit_buffer_remove_bit(buffer);

  bit_buffer_insert_bit(buffer, 1);
  traverse_trie(node->right, buffer, table, index);
  bit_buffer_remove_bit(buffer);
}

HuffmanTable *create_huffman_table(TrieNode *root, size_t num_characters) {
  HuffmanTable *table = malloc(sizeof(HuffmanTable));
  table->entries = malloc(num_characters * sizeof(HuffmanTableEntry));
  table->size = num_characters;

  bit_buffer *buffer = bit_buffer_empty();

  size_t index = 0;
  traverse_trie(root, buffer, table, &index);

  bit_buffer_free(buffer);

  return table;
}
