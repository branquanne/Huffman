#ifndef HUFFMAN_TABLE_H
#define HUFFMAN_TABLE_H

#include "bit_buffer.h"
#include "common_headers.h"
#include "trie.h"

typedef struct {
  unsigned char character;
  bit_buffer *bit_sequence;
} HuffmanTableEntry;

typedef struct {
  HuffmanTableEntry *entries;
  size_t size;
} HuffmanTable;

HuffmanTable *create_huffman_table(TrieNode *root, size_t num_characters);

void traverse_trie(TrieNode *node, bit_buffer *buffer, HuffmanTable *table, size_t *index);

#endif