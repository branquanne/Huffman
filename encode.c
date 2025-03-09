#include "encode.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * File: encode.c
 *
 * Description: This file contains the function for encoding files using
 * 				Huffman coding. The function compresses a file based on given 
 * 				Huffman codes. 
 * 
 * Author: Henrik Röjvall & Bran Quanne 
 * 
 * Date: 2025-03-08
 * 
 */

/* External functions */

void encode_file(char *input_filename, char *output_filename, char *codes[], long *input_size, long *output_size) {
	FILE *input_file = fopen(input_filename, "rb");
	FILE *output_file = fopen(output_filename, "wb");
	if (input_file == NULL || output_file == NULL) {
	  fprintf(stderr, "Error: Cannot open input or output file\n");
	  exit(1);
	}
  
	bit_buffer *buffer = bit_buffer_empty();
	int c;
	while ((c = fgetc(input_file)) != EOF) {
	  (*input_size)++;
	  if (c >= 0 && c < ASCII_SIZE) {
		char *code = codes[c];
		if (code == NULL) {
		  fprintf(stderr, "Error: Cannot encode character %d\n", c);
		  fclose(input_file);
		  fclose(output_file);
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
	*output_size = bit_buffer_size(buffer) / 8;
	free(byte_array);
  
	bit_buffer_free(buffer);
	fclose(input_file);
	fclose(output_file);
  }