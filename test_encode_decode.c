#include "encode_decode.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc test_freq_table.c freq_table.c -o test_freq_table

int main() {
  printf("=== Testing encoding and decoding functions ===\n");

  // Create a simple test file
  const char *test_input = "test_input.txt";
  const char *encoded_file = "test_encoded.bin";
  const char *decoded_file = "test_decoded.txt";

  FILE *f = fopen(test_input, "w");
  if (!f) {
    printf("Error creating test file\n");
    return 1;
  }

  const char *test_text = "This is a test. ABCDEFG. 123456!";
  fprintf(f, "%s", test_text);
  fclose(f);

  // Generate frequency table from the input
  int *freq = frequency_table(test_input);
  if (!freq) {
    printf("Error: frequency_table returned NULL\n");
    return 1;
  }

  // Build Huffman tree
  Node *root = build_huffman_tree(freq);
  if (!root) {
    printf("Error: build_huffman_tree returned NULL\n");
    free(freq);
    return 1;
  }

  // Generate codes
  char *codes[ASCII_SIZE] = {0};
  char code[ASCII_SIZE] = {0};
  generate_huffman_codes(root, code, 0, codes);

  // Test encode_file
  long input_size = 0;
  long output_size = 0;
  encode_file(test_input, encoded_file, codes, &input_size, &output_size);

  printf("Encoding results:\n");
  printf("%ld bytes read from %s.\n", input_size, test_input);
  printf("%ld bytes used in encoded form.\n", output_size);

  // Test decode_file
  decode_file(encoded_file, decoded_file, root);

  // Verify the decoded file matches the original
  f = fopen(decoded_file, "r");
  if (!f) {
    printf("Error opening decoded file\n");
    return 1;
  }

  char buffer[1024];
  size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, f);
  buffer[bytes_read] = '\0';
  fclose(f);

  printf("\nOriginal text: %s\n", test_text);
  printf("Decoded text:  %s\n", buffer);

  if (strcmp(test_text, buffer) == 0) {
    printf("Test PASSED: Decoded text matches original\n");
  } else {
    printf("Test FAILED: Decoded text doesn't match original\n");
  }

  // Cleanup
  free(freq);
  for (int i = 0; i < ASCII_SIZE; i++) {
    free(codes[i]);
  }
  free_huffman_tree(root);

  printf("=== Encoding/decoding tests complete ===\n");

  return 0;
}