#ifndef HUFFMAN_H
#define HUFFMAN_H

#define ASCII_SIZE 256

#include "bit_buffer.h"
#include "encode_decode.h"
#include "freq_table.h"
#include "huffman_table.h"
#include "list.h"
#include "pqueue.h"
#include "trie.h"
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
 * This module provides a compare function for nodes of a Huffman tree.
 * It also provides a function for validating command-line arguments.
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

/**
 * @brief Validate the command-line arguments.
 *
 * Checks whether the provided arguments match the expected format for
 * encoding or decoding operations.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of argument strings.
 *
 * @return true if the arguments are valid, false otherwise.
 *
 * @note If the arguments are invalid, an error message is printed to
 * stderr.
 */
bool validate_args(int argc, char *argv[]);

#endif // HUFFMAN_H

/**
 * @}
 */