#include "encode_decode.h"
#include "huffman_table.h"
#include "trie.h"

// Function to encode a file
void endodeFile(char *fileToEncode, char *outFile, HuffmanTable *table) {

  // Open the input file
  FILE *in = fopen(fileToEncode, "rb");
  if (in == NULL) {
    printf("Could not open file %s\n", fileToEncode);
    return;
  }

  // Open the output file
  FILE *out = fopen(outFile, "wb");
  if (out == NULL) {
    printf("Could not open file %s\n", outFile);
    fclose(in);
    return;
  }

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
  if (in == NULL) {
    printf("Could not open file %s\n", fileToDecode);
    return;
  }

  // Open the output file
  FILE *out = fopen(outFile, "wb");
  if (out == NULL) {
    printf("Could not open file %s\n", outFile);
    fclose(in);
    return;
  }

  // Create a bit buffer
  bit_buffer *buffer = bit_buffer_empty();

  // Read the input file character by character
  int c;
  while ((c = fgetc(in)) != EOF) {

    // Append the character to the buffer
    bit_buffer_append_byte(buffer, (unsigned char)c);
  }

  // Decode the buffer
  TrieNode *node = root;
  for (size_t i = 0; i < bit_buffer_size(buffer); i++) {

    // Traverse the Huffman Trie
    if (bit_buffer_get_bit(buffer, i) == 0) {
      node = node->left;
    } else {
      node = node->right;
    }

    // If the node is a leaf node, write the character to the output file
    if (node->left == NULL && node->right == NULL) {
      fputc(node->character, out);
      node = root;
    }
  }

  // Free the bit buffer
  bit_buffer_free(buffer);

  // Close the files
  fclose(in);
  fclose(out);
}