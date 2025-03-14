#ifndef HUFFMAN_H
#define HUFFMAN_H

#define ASCII_SIZE 256

#include "bit_buffer.h"
#include "encode.h"
#include "decode.h"
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

/*!
 * \mainpage Huffman Coding
 *
 * \section intro_sec Introduction
 * 
 * This program implements Huffman coding for compressing and decompressing text files. 
 * It follows these main steps:
 * 1. Construct a frequency table from the reference file. 
 * 2. Builds a Huffman tree (trie) based on character frequencies.
 * 3. Generates Huffman codes for efficient encoding. 
 * 4. Encodes or decodes files using the generated codes. 
 *
 * \section structure_sec Project Structure
 *
 * The project is modular, consisting of multiple source and header files, each representing a distinct 
 * part of the Huffman coding process. 
 *
 * \subsection files_sec Files
 *
 * **Main Components:**
 * - `huffman.c`-> Contains the main function and arrange encoding/decoding. 
 * - `huffman.h`-> Header for `huffman.c`, includes function declarations. 
 * 
 * 
 * **Encoding & Decoding:**
 * - `encode.c`-> Handles encoding logic. 
 * - `encode.h`-> Header for `encode.c`.
 * - `decode.c`-> Handles decoding logic.
 * - `decode.h`-> Header for `decode.c`.
 * 
 * **Data Structures:**
 * - `trie.c`-> Implements the Huffman tree (trie) for encoding/decoding.
 * - `trie.h`-> Header for `trie.c`.
 * - `pqueue.c`-> Implements the priority queue for Huffman tree construction.
 * - `pqueue.h`-> Header for `pqueue.c`.
 * - `list.c`-> Implements a linked list used by the priority queue.
 * - `list.h`-> Header for `list.c`.
 * 
 * **Support Functions:**
 * - `freq_table.c`-> Generates a character frequency table from input files.
 * - `freq_table.h`-> Header for `freq_table.c`.
 * - `huffman_table.c`-> Creates Huffman codes from the Huffman tree.
 * - `huffman_table.h`-> Header for `huffman_table.c`.
 * - `bit_buffer.c`-> Manages bitwise operations for efficient encoding.
 * - `bit_buffer.h`-> Header for `bit_buffer.c`. 
 * 
 * \subsection datatypes_sec Data Types
 *
 * The program uses several custom data structures to mange the Huffman coding process: 
 * 
 * **Custom Data Types:**
 * - `Node`-> Represents a node in the Huffman tree (`trie.h`). 
 * - `pqueue`-> A priority queue used to build the Huffman tree (`pqueue.h`). 
 * - `list`-> A doubly linked list used in the priority queue (`list.h`).
 * - `frequency_table`-> Stores character frequency counts (`freq_table.h`).
 * - `huffman_table`-> Maps characters to their Huffman codes (`huffman_table.h`).
 * - `bit_buffer`-> Stores and manipulates bits for encoding (`bit_buffer.h`).
 * 
 * **Data Type Relationships:**
 * - `frequency_table`-> Provides data to build the Huffman tree.
 * - `pqueue` -> Manages nodes during Huffman tree construction. 
 * - `bit_buffer`-> Ensures efficient bit level encoding.
 * - `huffman_table`-> Stores codes generated from the Huffman tree.
 * - `Node`-> Used in `trie.c` to construct the Huffman tree.
 *
 * \section usage_sec Usage
 *
 * The program is run from the command line and can either encode or decode files. 
 *
 * **Command Syntax:**
 * ```
 * huffman [OPTION] [FILE0] [FILE1] [FILE2]
 * ```
 * **Options:** 
 * - `-encode` Encodes `FILE1` based on frequency analysis from `FILE0`, storing the result in `FILE2`. 
 * - `-decode` Decodes `FILE1` using Huffman codes obtained from `FILE0`, restoring original content into `FILE2`. 
 *
 * **Example Usage:**
 * \code{.sh}
 * huffman -encode frequency.txt infile.txt outfile.encoded
 * huffman -decode frequency.txt infile.encoded outfile.decoded
 * \endcode
 *
 */

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