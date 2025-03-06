#include "common_headers.h"
#include "freq_table.h"
#include "huffman_table.h"
#include "trie.h"

int main(void) {

  int *frequencyTable = checkFrequency("test.txt");
  TrieNode *root = buildHuffmanTrie(frequencyTable);
  HuffmanTable *table = createHuffmanTable(root, MAX_ASCII_SIZE);

  // sort bit sequences by length
  // for (size_t i = 0; i < table->size; i++) {
  //   for (size_t j = i + 1; j < table->size; j++) {
  //     if (table->entries[i].bit_sequence->size > table->entries[j]->bit_sequence->size) {
  //       HuffmanTableEntry temp = table->entries[i];
  //       table->entries[i] = table->entries[j];
  //       table->entries[j] = temp;
  //     }
  //   }
  // }

  // for (size_t i = 0; i < table->size; i++) {
  //   printf("Character: %c, Bit sequence: %s\n", table->entries[i].character, bit_buffer_to_string(table->entries[i].bit_sequence));
  // }

  // Sort the Huffman Table by bit sequence length
  for (size_t i = 0; i < table->size; i++) {
    for (size_t j = i + 1; j < table->size; j++) {
      if ((bit_buffer_size(table->entries[i].bit_sequence) > bit_buffer_size(table->entries[j].bit_sequence))) {
        HuffmanTableEntry temp = table->entries[i];
        table->entries[i] = table->entries[j];
        table->entries[j] = temp;
      }
    }
  }

  for (size_t i = 0; i < table->size; i++) {
    printf("Character: %c, Bit sequence: %s\n", table->entries[i].character, bit_buffer_to_string(table->entries[i].bit_sequence));
  }

  // Print the Huffman Table using bit_puffer_print
  for (size_t i = 0; i < table->size; i++) {
    bit_buffer_print(table->entries[i].bit_sequence);
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