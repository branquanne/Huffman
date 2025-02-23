#ifndef VALIDATE_DATA_H
#define VALIDATE_DATA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @defgroup validate_data_h Validate Data
 *
 * @brief A module for validating input data.
 *
 * This module provides functions for validating input data and
 * reading data from files. The functions are used to check the
 * number of arguments, the validity of the options, and to load
 * characters from a file.
 *
 * @author  Henrik Röjvall & Bran Quanne
 * @since   2025-02-23
 *
 * @{
 */

/**
 * @brief Check the number of arguments.
 *
 * This function checks the number of arguments and exits the program
 * if there is an incorrect number of arguments.
 *
 * @param numberOfArguments The number of arguments.
 *
 * @return None.
 */
bool checkNumberOfArguments(int numberOfArguments);

/**
 * @brief Load characters from a file.
 *
 * This function reads and loads characters from a file and returns the characters
 * as a string.
 *
 * @param fileName The name of the file.
 *
 * @return The string of characters from the file.
 */
char *loadFileCharacters(char *fileName);

/**
 * @brief Check the validity of the options.
 *
 * This function checks the validity of the options and exits the program
 * if the options are invalid.
 *
 * @param arguments The arguments.
 *
 * @return None.
 */
bool checkOptionValidity(char **arguments);

#endif /* VALIDATE_DATA_H */

/**
 * @}
 */