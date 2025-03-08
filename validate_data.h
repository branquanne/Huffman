#ifndef VALIDATE_DATA_H
#define VALIDATE_DATA_H

#include <stdbool.h>

/**
 * @defgroup validate_data Huffman
 * 
 * @brief A module for validationg command-line arguments.
 * 
 * This module provides a function to validate the arguments provided
 * by the user to ensure correct usage of the program.
 * 
 * @author Henrik Röjvall & Bran Quanne
 * @since 2025-03-08
 * 
 * @{
 */

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

#endif // VALIDATE_DATA_H

/**
 * @}
 */