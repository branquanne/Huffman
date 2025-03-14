#ifndef ENCODE_H
#define ENCODE_H

#include "bit_buffer.h"
#include "freq_table.h"
#include "trie.h"

/**
 * @defgroup encode Encode
 * 
 * @brief A module for encoding files using Huffman coding.
 * 
 * This module provides a function to compress a file using Huffman coding.
 * 
 * @author Henrik Röjvall & Bran Quanne
 * @since 2025-03-08
 * 
 * @{
 */

/**
 * @brief Encodes a file using Huffman coding. 
 * 
 * Converts an input file into a compressed format using predefined codes
 * and stores the result in an output file. 
 * 
 * @param input_filename The name of the input file to encode.
 * @param output_filename The name of the output file to store the encoded data.
 * @param codes An array of Huffman codes for each character.
 * @param input_size Pointer to store the input file size.
 * @param output_size Pointer to store the output file size.
 * 
 * @return -
 * 
 * @see decode_file
 * 
 */
void encode_file(char *input_filename, char *output_filename, char *codes[], long *input_size, long *output_size);

#endif // ENCODE_H

/**
 * @}
 */