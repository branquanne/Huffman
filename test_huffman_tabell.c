#include "freq_table.h"
#include "huffman_tabell.h"
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // read file
  int *frequencyTable = checkFrequency("löremipsum.txt");

  // Create huffman trie
  TrieNode *root = buildHuffmanTrie(frequencyTable);

  // create table
  HuffmanTable *table = create_huffman_table(root, 256);

  // print table
  for (size_t i = 0; i < table->size; i++) {
    printf("Character: %c, Bit sequence: ", table->entries[i].character);
    bit_buffer_print(table->entries[i].bit_sequence);
  }

  // free memory
  freeTrie(root);
  free(frequencyTable);
  free(table);

  return 0;
}