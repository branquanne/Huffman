#include "huffman.h"
#include "bit_buffer.h"
#include "encode_decode.h"
#include "freq_table.h"
#include "pqueue.h"
#include "validate_data.h"
/* G*/

int main(int argc, char **argv) {

  // Validera körningsargument (kan bryta ut till egen funktion)
  validateData(argc, argv);

  char *option = argv[1];
  char *file0 = argv[2];
  char *file1 = argv[3];
  char *file2 = argv[4];

  int *freq_table = checkFrequency(file0);

  // Skapa huffman trie
  TrieNode *root = buildHuffmanTrie(freq_table);

  if (strcmp(option, "-encode")) {
    // Skapa huffman tabell
    HuffmanTable *table = createHuffmanTable(root, MAX_ASCII_SIZE);
    encodeFile(file1, file2, table);
  } else if (strcmp(option, "-decode")) {
    // decode
    decodeFile(file1, file2, root);
  }

  // Validera input -> Frekvensanalys (file0) -> skapa huffman trie -> skapa
  // huffmantabell -> encode (okomprimerad blir komprimerad)
  //
  // Validera input -> Frekvensanalys (file0) -> skapa huffman trie  ->
  // decode (komprimerad återställs till original)

  free(freq_table);
  freeTrie(root);

  return root;
}

void validateData(int argc, char **argv) {

  for (int i = 2; i < argc; i++) {
    checkInFile(argv[i]);
  }

  if (checkNumberOfArguments(argc) == false) {
    printf(stderr, "Invalid number of arguments\n");
    exit(1);
  }

  if (checkOptionValidity(argv) == false) {
    printf(stderr, "Invalid option\n");
    exit(1);
  }

  Node *current = root;
  int bit;
  while ((bit = fgetc(input_file)) != EOF) {
    for (int i = 7; i >= 0; i--) {
      current = (bit & (1 << i)) ? current->right : current->left;
      if (!current->left && !current->right) {
        fputc(current->data, output_file);
        current = root;
      }
    }
  }

  fclose(input_file);
  fclose(output_file);
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