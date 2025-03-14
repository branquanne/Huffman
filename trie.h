#ifndef TRIE_H
#define TRIE_H

#include "freq_table.h"
#include "pqueue.h"

/**
 * @defgroup trie_h Trie
 *
 * @brief A module for building a Huffman tree using a priority queue.
 *
 * This module provides functions to create a new node and build a Huffman
 * tree based on character frequency.
 *
 * @author Henrik Röjvall & Bran Quanne
 * @since 2025-03-08
 *
 * @{
 */

/**
 * @brief A structure to represent a node in the Huffman tree.
 *
 * Each node stores a character, its frequency, and pointers to left and
 * right child nodes.
 */
typedef struct Node {
  char data;                 /**< The character stored in the node */
  unsigned freq;             /**< The frequency of the character */
  struct Node *left, *right; /**< Pointers to the left and right child nodes */
} Node;

/**
 * @brief Creates a new Huffman tree node.
 *
 * Allocates memory for a new node and initializes its data and frequency.
 *
 * @param data The character to store in the node.
 * @param freq The frequency of the character.
 *
 * @return A pointer to the newly created node.
 *
 * @note The caller is responsible for managing the allocated memory.
 */
Node *create_node(char data, int freq);

/**
 * @brief Builds a Huffman tree from character frequencies.
 *
 * Constructs a Huffman tree using a priority queue where nodes with the lowest
 * frequency have the highest priority.
 *
 * @param freq An array representing the frequency of each ASCII character.
 *
 * @return A pointer to the root node of the Huffman tree.
 *
 * @note The caller is responsible for freeing the allocated memory when done. This can be done using free_huffman_tree().
 */
Node *build_huffman_tree(int *freq);

/**
 * @brief Frees the memory allocated for the Huffman tree.
 *
 * Recursively frees the memory allocated for each node in the Huffman tree.
 *
 * @param root A pointer to the root node of the Huffman tree.
 * 
 * @return -
 * 
 */
void free_huffman_tree(Node *root);

#endif // TRIE_H

/**
 * @}
 */