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

int node_cmp(void *a, void *b);

#endif // HUFFMAN_H