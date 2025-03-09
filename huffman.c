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
  Node *root = build_huffman_tree(freq);

  char *codes[ASCII_SIZE] = {0};
  char code[ASCII_SIZE];
  generate_huffman_codes(root, code, 0, codes);

  if (strcmp(argv[1], "-encode") == 0) {
    long input_size = 0;
    long output_size = 0;
    encode_file(argv[3], argv[4], codes, &input_size, &output_size);
    printf("%ld bytes read from %s.\n", input_size, argv[3]);
    printf("%ld bytes used in encoded form.\n", output_size);
  } else if (strcmp(argv[1], "-decode") == 0) {
    decode_file(argv[3], argv[4], root);
    printf("File decoded succesfully.\n");
  }

  free(freq);
  for (int i = 0; i < ASCII_SIZE; ++i) {
    free(codes[i]);
  }
  free_huffman_tree(root);

  return 0;
}

bool validate_args(int argc, char *argv[]) {
  if (argc != 5) {
    printf("USAGE: \n");
    printf("%s [OPTION] [FILE0] [FILE1] [FILE2]\n", argv[0]);
    printf("Options: \n");
    printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
    printf("-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
    return false;
  }

  if (strcmp(argv[1], "-encode") != 0 && strcmp(argv[1], "-decode") != 0) {
    printf("USAGE: \n");
    printf("%s [OPTION] [FILE0] [FILE1] [FILE2]\n", argv[0]);
    printf("Options: \n");
    printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
    printf("-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
    return false;
  }
  return true;
}