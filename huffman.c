#include "huffman.h"
#include "bit_buffer.h"
#include "pqueue.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SIZE 256

int node_cmp(void *a, void *b) {
  return ((Node *)a)->freq - ((Node *)b)->freq;
}

bool validate_args(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s -encode|-decode <frequency_file> <input_file> <output_file>\n", argv[0]);
    return false;
  }

  if (strcmp(argv[1], "-encode") != 0 && strcmp(argv[1], "-decode") != 0) {
    fprintf(stderr, "Usage: %s -encode|-decode <frequency_file> <input_file> <output_file>\n", argv[0]);
    return false;
  }
  return true;
}

int *frequency_table(char *fileName) {
  FILE *inFile = fopen(fileName, "rb");
  if (inFile == NULL) {
    fprintf(stderr, "Error: Cannot open file %s\n", fileName);
    exit(1);
  }

  int *frequencyTable = (int *)malloc(ASCII_SIZE * sizeof(int));
  for (int i = 0; i < ASCII_SIZE; i++) {
    frequencyTable[i] = 0;
  }
  if (frequencyTable == NULL) {
    fprintf(stderr, "Error: Cannot allocate memory\n");
    exit(1);
  }

  int ch;
  while ((ch = fgetc(inFile)) != EOF) {
    if (ch >= 0 && ch < ASCII_SIZE) {
      frequencyTable[ch]++;
    } else {
      fprintf(stderr, "Warning: Character out of range %d\n", ch);
    }
  }

  fclose(inFile);
  return frequencyTable;
}

// Function to generate Huffman codes
void generate_huffman_codes(Node *root, char *code, int top, char *codes[]) {
  if (root->left) {
    code[top] = '0';
    generate_huffman_codes(root->left, code, top + 1, codes);
  }

  if (root->right) {
    code[top] = '1';
    generate_huffman_codes(root->right, code, top + 1, codes);
  }

  if (!root->left && !root->right) {
    code[top] = '\0';
    codes[(unsigned char)root->data] = strdup(code);
  }
}

// Function to create a new node
Node *create_node(char data, int freq) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "Error: Cannot allocate memory\n");
    exit(1);
  }

  node->data = data;
  node->freq = freq;
  node->left = node->right = NULL;

  return node;
}

// Function to build the Huffman tree
Node *build_huffman_tree(int *freq) {
  pqueue *pq = pqueue_empty(node_cmp);
  int pqueue_count = 0; // Initialize a counter for the priority queue size

  // First, add all characters with non-zero frequency
  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (freq[i]) {
      pqueue_insert(pq, create_node((char)i, freq[i]));
      pqueue_count++; // Increment the counter when inserting a node
    }
  }

  // If no characters were added (empty file), add at least one
  if (pqueue_count == 0) {
    pqueue_insert(pq, create_node('\0', 1));
    pqueue_count++;
  }

  // Add characters with zero frequency, giving them a very small frequency (1)
  // to ensure they get included in the tree
  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (freq[i] == 0) {
      pqueue_insert(pq, create_node((char)i, 1));
      pqueue_count++; // Increment the counter when inserting a node
    }
  }

  while (pqueue_count > 1) { // Use the counter instead of pqueue_size
    Node *left = pqueue_inspect_first(pq);
    pqueue_delete_first(pq);
    pqueue_count--; // Decrement the counter when deleting a node

    Node *right = pqueue_inspect_first(pq);
    pqueue_delete_first(pq);
    pqueue_count--; // Decrement the counter when deleting a node

    Node *top = create_node('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    pqueue_insert(pq, top);
    pqueue_count++; // Increment the counter when inserting a node
  }

  Node *root = pqueue_inspect_first(pq);
  pqueue_kill(pq);

  return root;
}

// Function to encode the input file
void encode_file(char *input_filename, char *output_filename, char *codes[]) {
  FILE *input_file = fopen(input_filename, "rb");
  FILE *output_file = fopen(output_filename, "wb");
  if (input_file == NULL || output_file == NULL) {
    fprintf(stderr, "Error: Cannot open input or output file\n");
    exit(1);
  }

  bit_buffer *buffer = bit_buffer_empty();
  int c;
  while ((c = fgetc(input_file)) != EOF) {
    if (c >= 0 && c < ASCII_SIZE) {
      char *code = codes[c];
      if (code == NULL) {
        fprintf(stderr, "Error: Cannot encode character %d\n", c);
        exit(1);
      }
      for (int i = 0; code[i] != '\0'; ++i) {
        bit_buffer_insert_bit(buffer, code[i] == '1');
      }
    } else {
      fprintf(stderr, "Error: Character out of range %d\n", c);
      exit(1);
    }
  }

  while (bit_buffer_size(buffer) % 8 != 0) {
    bit_buffer_insert_bit(buffer, 0);
  }
  char *byte_array = bit_buffer_to_byte_array(buffer);
  fwrite(byte_array, sizeof(char), bit_buffer_size(buffer) / 8, output_file);
  free(byte_array);

  bit_buffer_free(buffer);
  fclose(input_file);
  fclose(output_file);
}

// Function to decode the input file
void decode_file(char *input_filename, char *output_filename, Node *root) {
  FILE *input_file = fopen(input_filename, "rb");
  FILE *output_file = fopen(output_filename, "wb");
  if (input_file == NULL || output_file == NULL) {
    fprintf(stderr, "Error: Cannot open input or output file\n");
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