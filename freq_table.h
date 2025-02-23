#ifndef FREQ_TABLE_H
#define FREQ_TABLE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @defgroup freq_table_h Frequency Table
 * 
 * @brief A module for creating a frequency table.
 * 
 * This module provides a function for creating a frequency table
 * from a string of characters. The frequency table is an array
 * of integers where each index represents a character and the 
 * value at that index represents the frequency of that character.
 * 
 * @author  Henrik Röjvall & Bran Quanne
 * @since   2025-02-23
 * 
 * @{
 */

/**
 * @brief Create a frequency table.
 * 
 * This function creates a frequency table from a string of characters.
 * The frequency table is an array of integers where each index represents
 * a character and the value at that index represents the frequency of that
 * character.
 * 
 * @param fileContents The string of characters.
 * 
 * @return The frequency table.
 */
int *checkFrequency(char *fileContents);

#endif /* FREQ_TABLE_H */

/**
 * @}
 */