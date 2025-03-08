#include <string.h>
#include <stdlib.h>
#include "huffman.h"

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
	  codes[(unsigned char)root->data] = strcpy(malloc(strlen(code) + 1), code);
	}
  }
  
  