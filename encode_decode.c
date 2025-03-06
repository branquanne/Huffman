#include "encode_decode.h"
#include "bit_buffer.h"
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

    // Find the character in the Huffman Table
    for (size_t i = 0; i < table->size; i++) {
      if (table->entries[i].character == (unsigned char)c) {

        // Append the bit sequence to the buffer
        bit_buffer_append(buffer, table->entries[i].bit_sequence);
        break;
      }
    }
  }

  // Write the buffer to the output file
  bit_buffer_write(buffer, out);

  // Free the byte array
  free(byteArray);

  // Clear the bit buffer
  bit_buffer_clear(buffer); 

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
  while (bit_index < bit_buffer_size(buffer) * 8) {
    size_t byte_index = bit_index / 8;
    size_t bit_in_byte = bit_index % 8;
    int bit = (buffer->array[byte_index] >> (7 - bit_in_byte)) & 1;

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