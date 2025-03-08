#ifndef HUFFMAN_TABLE_H
#define HUFFMAN_TABLE_H

#include "trie.h"

// Function to generate Huffman codes
void generate_huffman_codes(Node *root, char *code, int top, char *codes[]);

#endif // HUFFMAN_TABLE_H