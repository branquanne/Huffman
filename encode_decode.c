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
    for (size_t i = 0; i < table->size; i++) {
      if (table->entries[i].character == c) {
        for (size_t j = 0; j < bit_buffer_size(table->entries[i].bit_sequence); j++) {
          bit_buffer_insert_bit(buffer, bit_buffer_inspect_bit(table->entries[i].bit_sequence, j));
        }
        break;
      }
    } 
  }

  char *byteArray = bit_buffer_to_byte_array(buffer);
  size_t byteArraySize = (bit_buffer_size(buffer) + 7) / 8; // Calculate the number of bytes
  fwrite(byteArray, 1, byteArraySize, out);
  free(byteArray);
  // Free the byte array
  free(byteArray);

  // Clear the bit buffer
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
  }

  TrieNode *node = root;
  size_t bit_index = 0;
  while (bit_index < bit_buffer_size(buffer)) {
    int bit = bit_buffer_inspect_bit(buffer, bit_index);

    if (bit == 0) {
      node = node->left;
    } else {
      node = node->right;
    }

    if (node->left == NULL && node->right == NULL) {
      fputc(node->character, out);
      node = root;
    }

    bit_index++;
  }

  // Free the bit buffer
  bit_buffer_free(buffer);

  // Close the files
  fclose(in);
  fclose(out);
}