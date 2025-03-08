#include "huffman.h"

int node_cmp(void *a, void *b) {
  return ((Node *)a)->freq - ((Node *)b)->freq;
}

// Main function
int main(int argc, char **argv) {
  if (!validate_args(argc, argv)) {
    return 1;
  }

  int *freq = frequency_table(argv[2]);

  printf("Frequency table ok!\n");

  Node *root = build_huffman_tree(freq);

  printf("Huffman tree ok!\n");

  char *codes[ASCII_SIZE] = {0};
  char code[ASCII_SIZE];
  generate_huffman_codes(root, code, 0, codes);

  printf("Huffman codes ok!\n");

  if (strcmp(argv[1], "-encode") == 0) {
    encode_file(argv[3], argv[4], codes);

    printf("File encoded ok!\n");
  } else if (strcmp(argv[1], "-decode") == 0) {
    decode_file(argv[3], argv[4], root);

    printf("File decoded ok!\n");
  }

  free(freq);
  for (int i = 0; i < ASCII_SIZE; ++i) {
    free(codes[i]);
  }
  free(root);

  printf("Memory freed ok!\n");

  return 0;
}