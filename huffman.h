#ifndef HUFFMAN_H
#define HUFFMAN_H

#define ASCII_SIZE 256

#include "bit_buffer.h"
#include "pqueue.h"
#include "list.h"
#include "freq_table.h"
#include "validate_data.h"
#include "encode_decode.h"
#include "trie.h"
#include "huffman_table.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @defgroup huffman_h Huffman
 * 
 * @brief A module for implementing Huffman coding for file compression
 * and decompression.
 * 
 * This module provides a compare function for nodes of a Huffman tree.abort
 * 
 * @author Henrik Röjvall & Bran Quanne
 * @since 2025-03-08
 * 
 * @{
 */


/**
 * @brief Compares two huffman tree nodes based on their frequency.
 * 
 * Used as a comparator function for the priority queue.
 * 
 * @param a A pointer to the first node.
 * @param b A pointer to the second node.
 * 
 * @return A negative value if a has lower frequency than b, 
 * a positive value if a has a higher frequenxy, and zero if they are equal.
 */
int node_cmp(void *a, void *b);

#endif // HUFFMAN_H

/**
 * @}
 */