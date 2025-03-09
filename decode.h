#ifndef DECODE_H
#define DECODE_H

#include "bit_buffer.h"
#include "freq_table.h"
#include "trie.h"

/**
 * @defgroup decode Decode
 * 
 * @brief A module for decoding files using Huffman coding.
 * 
 * This module provides a function to decompress a file using 
 * Huffman coding.
 * 
 * @author Henrik Röjvall & Bran Quanne
 * @since 2025-03-08
 * 
 * @{
 */

/**
 * @brief Decodes a file using Huffman coding.
 * 
 * Restores the original content from a compressed file and writes
 * the decoded data to an output file. 
 * 
 * @param input_filename The name of the file to be decoded.
 * @param output_filename The name of the output file. 
 * @param root The root of the Huffman tree used for decoding. 
 * 
 * @return -
 * 
 * @see encode_file
 * 
 */
void decode_file(char *input_filename, char *output_filename, Node *root);

#endif // DECODE_H

/**
 * @}
 */