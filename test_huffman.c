#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// gcc test_huffman.c huffman.c encode_decode.c trie.c freq_table.c huffman_table.c -o test_huffman

void create_test_file(const char *filename, const char *content) {
  FILE *f = fopen(filename, "w");
  if (!f) {
    printf("Error creating test file %s\n", filename);
    exit(1);
  }
  fprintf(f, "%s", content);
  fclose(f);
}

void test_integration() {
  printf("=== Testing full Huffman compression pipeline ===\n");

  // Create test files
  create_test_file("sample.txt", "AAAAAABBBBCCCD"); // Frequency source
  create_test_file("input.txt", "ABABCABCDABCDE");  // Input to encode

  // Test encoding
  char *encode_args[] = {"huffman", "-encode", "sample.txt", "input.txt", "output.bin"};
  printf("\nTesting encoding:\n");
  printf("Command: huffman -encode sample.txt input.txt output.bin\n");

  if (!validate_args(5, encode_args)) {
    printf("Error: validate_args failed for encoding\n");
    return;
  }

  int *freq = frequency_table(encode_args[2]);
  Node *root = build_huffman_tree(freq);

  char *codes[ASCII_SIZE] = {0};
  char code[ASCII_SIZE];
  generate_huffman_codes(root, code, 0, codes);

  long input_size = 0;
  long output_size = 0;
  encode_file(encode_args[3], encode_args[4], codes, &input_size, &output_size);

  printf("%ld bytes read from %s.\n", input_size, encode_args[3]);
  printf("%ld bytes used in encoded form.\n", output_size);

  // Test decoding
  char *decode_args[] = {"huffman", "-decode", "sample.txt", "output.bin", "decoded.txt"};
  printf("\nTesting decoding:\n");
  printf("Command: huffman -decode sample.txt output.bin decoded.txt\n");

  if (!validate_args(5, decode_args)) {
    printf("Error: validate_args failed for decoding\n");
    return;
  }

  decode_file(decode_args[3], decode_args[4], root);
  printf("File decoded successfully.\n");

  // Verify decoded content
  FILE *f = fopen("decoded.txt", "r");
  if (!f) {
    printf("Error opening decoded file\n");
    return;
  }

  char buffer[1024];
  size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, f);
  buffer[bytes_read] = '\0';
  fclose(f);

  printf("\nOriginal text: ABABCABCDABCDE\n");
  printf("Decoded text:  %s\n", buffer);

  if (strcmp("ABABCABCDABCDE", buffer) == 0) {
    printf("Test PASSED: Decoded text matches original\n");
  } else {
    printf("Test FAILED: Decoded text doesn't match original\n");
  }

  // Test invalid arguments
  printf("\nTesting invalid arguments:\n");
  char *invalid_args[] = {"huffman"};
  printf("Command: huffman\n");

  if (!validate_args(1, invalid_args)) {
    printf("Test PASSED: Correctly rejected invalid arguments\n");
  } else {
    printf("Test FAILED: Incorrectly accepted invalid arguments\n");
  }

  // Cleanup
  free(freq);
  for (int i = 0; i < ASCII_SIZE; ++i) {
    free(codes[i]);
  }
  free_huffman_tree(root);

  printf("=== Integration tests complete ===\n");
}

int main() {
  test_integration();
  return 0;
}