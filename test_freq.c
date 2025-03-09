#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc test_encode_decode.c encode_decode.c trie.c freq_table.c -o test_encode_decode

int main() {
  printf("=== Testing frequency table generation ===\n");

  // Test with a simple file
  const char *test_filename = "freq_test.txt";
  FILE *f = fopen(test_filename, "w");
  if (!f) {
    printf("Error creating test file\n");
    return 1;
  }
  fprintf(f, "aaabbc");
  fclose(f);

  int *freq = frequency_table(test_filename);
  if (!freq) {
    printf("Error: frequency_table returned NULL\n");
    return 1;
  }

  printf("Expected frequencies:\n");
  printf("'a': 3\n'b': 2\n'c': 1\n");

  printf("Actual frequencies:\n");
  printf("'a': %d\n'b': %d\n'c': %d\n", freq['a'], freq['b'], freq['c']);

  // Check a few values
  if (freq['a'] != 3 || freq['b'] != 2 || freq['c'] != 1) {
    printf("Test FAILED: Frequency counts don't match expected values\n");
  } else {
    printf("Test PASSED: Frequency counts match expected values\n");
  }

  // Test with empty file
  f = fopen("empty_test.txt", "w");
  fclose(f);

  int *empty_freq = frequency_table("empty_test.txt");
  if (!empty_freq) {
    printf("Error handling empty file: frequency_table returned NULL\n");
  } else {
    printf("Empty file test: frequency_table handled empty file\n");
    free(empty_freq);
  }

  free(freq);
  printf("=== Frequency table tests complete ===\n");

  return 0;
}