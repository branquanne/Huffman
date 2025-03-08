#ifndef HUFFMAN_TABLE_H
#define HUFFMAN_TABLE_H

#include "trie.h"

/**
 * @defgroup huffman_table_h Huffman
 * 
 * @brief A module for generationg Huffman codes from a Huffman tree.abort
 * 
 * This module provides a function to generate binary Huffman codes
 * for characters based on their frequency.
 * 
 * @author Henrik Röjvall & Bran Quanne
 * @since 2025-03-08
 * 
 * @{
 */

/**
 * @brief Generates Huffman codes for characters in the Huffman tree.
 * 
 * Traverses the Huffman tree recursively to assign binary codes to
 * each character and stores them in an array.
 * 
 * @param root The root of the Huffman tree.
 * @param code Array used to store the current Huffman code during traversal.
 * @param top Index representing the current position in the code array.
 * @param codes Array where the generated Huffman codes will be stored.
 * 
 */
void generate_huffman_codes(Node *root, char *code, int top, char *codes[]);

#endif // HUFFMAN_TABLE_H

/** 
 * @} 
 */