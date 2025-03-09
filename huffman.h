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

/*!
 * \mainpage Huffman Coding Project
 *
 * \section intro_sec Introduction
 *
 * Huffman Coding is a data compression algorithm used by several popular file formats such as ZIP, JPEG, and MP3 as part of the compression process.
 * This project involves implementing a program that compresses and decompresses text files using Huffman coding.
 *
 * \section structure_sec Project Structure
 *
 * The project consists of several source and header files, each of which implements a specific part of the Huffman coding process.
 *
 * \subsection files_sec Files
 *
 * - `huffman.c`: Contains the main function and orchestrates the encoding and decoding processes.
 * - `huffman.h`: Header file for `huffman.c`, includes function declarations and necessary includes.
 * - `encode_decode.c`: Implements functions for encoding and decoding files.
 * - `encode_decode.h`: Header file for `encode_decode.c`.
 * - `freq_table.c`: Implements functionality to create and manage the frequency table.
 * - `freq_table.h`: Header file for `freq_table.c`.
 * - `huffman_table.c`: Implements the Huffman table used for encoding and decoding.
 * - `huffman_table.h`: Header file for `huffman_table.c`.
 * - `trie.c`: Implements the trie data structure for Huffman coding.
 * - `trie.h`: Header file for `trie.c`.
 *
 * \subsection datatypes_sec Data Types
 *
 * The project uses several custom data types, some of which are provided and some are implemented as part of the project:
 *
 * - `Node`: Represents a node in the Huffman tree (defined in `trie.h`).
 * - `bit_buffer`: Used for handling operations involving bits (defined in `bit_buffer.h`).
 * - `frequency_table`: Represents the frequency of each byte in the input file (defined in `freq_table.h`).
 * - `huffman_table`: Represents the Huffman codes for each byte (defined in `huffman_table.h`).
 * - `list`: A doubly linked list used by the priority queue (defined in `list.h`).
 * - `pqueue`: A priority queue used during the construction of the Huffman tree (defined in `pqueue.h`).
 *
 * \section usage_sec Usage
 *
 * The program is run from the command line and can be used to either encode or decode files:
 *
 * USAGE: 
 * huffman [OPTION] [FILE0] [FILE1] [FILE2]
 * Options: 
 * -encode encodes FILE1 according to frequency analysis done on FILE0. Stores the result in FILE2
 * -decode decodes FILE1 according to frequency analysis done on FILE0. Stores the result in FILE2
 *
 * Example commands:
 *
 * \code{.sh}
 * huffman -encode frequence.txt infil.txt utfil.kodad
 * huffman -decode frequence.txt infil.kodad utfil.txt
 * \endcode
 *
 * \section contact_sec Contact
 *
 * For any issues or inquiries, please contact the course responsible.
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