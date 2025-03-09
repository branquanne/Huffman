#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

// gcc test_huffman_table.c huffman_table.c trie.c -o test_huffman_table

void print_code_lengths(char *codes[]) {
  printf("Code lengths for characters:\n");
  for (int i = 0; i < ASCII_SIZE; i++) {
    if (codes[i] != NULL) {
      printf("'%c' (ASCII %d): %ld bits\n",
             i,
             i,
             strlen(codes[i]));
    }
  }
}

int main() {
  printf("=== Testing Huffman table generation ===\n");

  // Create sample frequency tables
  int *freq_uniform = calloc(ASCII_SIZE, sizeof(int));
  int *freq_skewed = calloc(ASCII_SIZE, sizeof(int));

  // Uniform frequency distribution
  freq_uniform['a'] = 10;
  freq_uniform['b'] = 10;
  freq_uniform['c'] = 10;
  freq_uniform['d'] = 10;

  // Skewed frequency distribution
  freq_skewed['a'] = 70;
  freq_skewed['b'] = 15;
  freq_skewed['c'] = 10;
  freq_skewed['d'] = 5;

  // Test with uniform distribution
  printf("\nTesting with uniform frequency distribution:\n");
  Node *root_uniform = build_huffman_tree(freq_uniform);
  char *codes_uniform[ASCII_SIZE] = {0};
  char code_uniform[ASCII_SIZE] = {0};
  generate_huffman_codes(root_uniform, code_uniform, 0, codes_uniform);

  print_code_lengths(codes_uniform);

  // Test with skewed distribution
  printf("\nTesting with skewed frequency distribution:\n");
  Node *root_skewed = build_huffman_tree(freq_skewed);
  char *codes_skewed[ASCII_SIZE] = {0};
  char code_skewed[ASCII_SIZE] = {0};
  generate_huffman_codes(root_skewed, code_skewed, 0, codes_skewed);

  print_code_lengths(codes_skewed);

  // With the skewed distribution, 'a' should have the shortest code
  printf("\nVerifying optimal code assignment:\n");
  if (codes_skewed['a'] && strlen(codes_skewed['a']) <= strlen(codes_skewed['b']) &&
      strlen(codes_skewed['b']) <= strlen(codes_skewed['d'])) {
    printf("Test PASSED: Most frequent character has shortest code\n");
  } else {
    printf("Test FAILED: Code lengths not optimal\n");
  }

  // Cleanup
  free(freq_uniform);
  free(freq_skewed);

  for (int i = 0; i < ASCII_SIZE; i++) {
    free(codes_uniform[i]);
    free(codes_skewed[i]);
  }

  free_huffman_tree(root_uniform);
  free_huffman_tree(root_skewed);

  printf("=== Huffman table tests complete ===\n");

  return 0;
}