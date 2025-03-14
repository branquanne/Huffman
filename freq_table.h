#ifndef FREQ_TABLE_H
#define FREQ_TABLE_H

#define ASCII_SIZE 256

#include <stdio.h>
#include <stdlib.h>

/**
 * @defgroup freq_table Frequency Table
 *
 * @brief A module for generating a frequency table for characters in a file.
 *
 * This module provides a function to generate a frequency table for characters
 * in a given file. The table counts occurrences of each ASCII character in the file.
 *
 * @author Henrik Röjvall & Bran Quanne
 * @since 2025-03-08
 *
 * @{
 */

/**
 * @brief Generates a frequency table for characters in a file.
 *
 * Reads a file and counts the occurrences of each ASCII character in the file.
 * The function returns an array where the index represents the ASCII value of a character
 * and the value represents the number of occurrences of that character in the file.
 *
 * @param fileName The name of the file to generate the frequency table for.
 *
 * @return An array representing the frequency table for characters in the file.
 *
 * @note The caller is responsible for freeing the memory allocated for the frequency table.
 *
 */
int *frequency_table(char *fileName);

#endif // FREQ_TABLE_H

/**
 * @}
 */