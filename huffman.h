#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdbool.h>

// Define the Node structure
typedef struct Node {
  char data;
  unsigned freq;
  struct Node *left, *right;
} Node;

// Function declarations
int node_cmp(void *a, void *b);
bool validate_args(int argc, char *argv[]);
int *frequency_table(char *filename);
Node *build_huffman_tree(int *freq);
void generate_huffman_codes(Node *root, char *code, int top, char *codes[]);
void encode_file(char *input_filename, char *output_filename, char *codes[]);
void decode_file(char *input_filename, char *output_filename, Node *root);
Node *create_node(char data, int freq); // Add this line

#endif // HUFFMAN_H
