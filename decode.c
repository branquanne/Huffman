#include "decode.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * File: decode.c
 *
 * Description: This file contains the function for decoding files using
 * 				Huffman coding. The function reconstructs the original data
 * 				using a Huffman tree. 
 * 
 * Author: Henrik Röjvall & Bran Quanne 
 * 
 * Date: 2025-03-08
 * 
 */

/* External functions */

void decode_file(char *input_filename, char *output_filename, Node *root) {
	FILE *input_file = fopen(input_filename, "rb");
	FILE *output_file = fopen(output_filename, "wb");
	if (input_file == NULL || output_file == NULL) {
	  fprintf(stderr, "Error: Cannot open input or output file\n");
	  exit(1);
	}
  
	Node *current = root;
	if (!root) {
		fprintf(stderr, "Error: Huffman tree is NULL. Cannot decode.\n");
		fclose(input_file);
		fclose(output_file);
		exit(1);
	}
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