#include "encode_decode.h"
#include "huffman_table.h"
#include "trie.h"

// Function to encode a file
void encodeFile(char *fileToEncode, char *outFile, HuffmanTable *table) {

  // Open the input file
  FILE *in = fopen(fileToEncode, "rb");

  // Open the output file
  FILE *out = fopen(outFile, "wb");

  // Create a bit buffer
  bit_buffer *buffer = bit_buffer_empty();

  // Read the input file character by character
  int c;
  while ((c = fgetc(in)) != EOF) {

    // Get the Huffman Table Entry for the character
    HuffmanTableEntry entry = table->entries[(unsigned char)c];

    // Insert the bit sequence into the buffer
    for (int i = 0; i < bit_buffer_size(entry.bit_sequence); i++) {
      bit_buffer_insert_bit(buffer, bit_buffer_inspect_bit(entry.bit_sequence, i));
    }
  }

  // Write the buffer to the output file
  for (size_t i = 0; i < (bit_buffer_size(buffer) + 7) / 8; i++) {
    fputc(bit_buffer_remove_byte(buffer), out);
  }

  // Free the bit buffer
  bit_buffer_free(buffer);

  // Close the files
  fclose(in);
  fclose(out);
}

// Function to decode a file
void decodeFile(char *fileToDecode, char *outFile, TrieNode *root) {

  // Open the input file
  FILE *in = fopen(fileToDecode, "rb");

  // Open the output file
  FILE *out = fopen(outFile, "wb");

  // Create a bit buffer
  bit_buffer *buffer = bit_buffer_empty();

  // Read the input file character by character
  int c;
  while ((c = fgetc(in)) != EOF) {

    // Append the character to the buffer
    bit_buffer_insert_byte(buffer, (unsigned char)c);

    // Traverse the Huffman Trie
    TrieNode *node = root;
    TrieNode *node = root;
    for (size_t i = 0; i < bit_buffer_size(buffer); i++) {
      int bit = bit_buffer_get_bit_value(buffer, i);
      if (bit == 0) {
        node = node->left;
      } else {
        node = node->right;
      }

      if (node->left == NULL && node->right == NULL) {
        fputc(node->character, out);
        node = root;
      }
    }

    // Write the character to the output file
    fputc(node->character, out);
  }

  // Free the bit buffer
  bit_buffer_free(buffer);

  // Close the files
  fclose(in);
  fclose(out);
}