#include "freq_table.h"
#include "huffman_tabell.h"
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

// Sort the Huffman table by shortest bit sequence 

int main(void) {

  int *frequencyTable = checkFrequency("löremipsum.txt");
  TrieNode *root = buildHuffmanTrie(frequencyTable);
  HuffmanTable *table = create_huffman_table(root, 256);

  for (size_t i = 0; i < table->size; i++) {
    printf("Character: %c, Bit sequence: %s\n", table->entries[i].character, bit_buffer_to_string(table->entries[i].bit_sequence));
  }

  free(frequencyTable);
  freeTrie(root);
  for (size_t i = 0; i < table->size; i++) {
    bit_buffer_free(table->entries[i].bit_sequence);
  }
  free(table->entries);
  free(table);

  return 0;
}