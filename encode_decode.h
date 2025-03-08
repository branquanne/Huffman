#ifndef ENCODE_DECODE_H
#define ENCODE_DECODE_H

#include "trie.h"
#include "bit_buffer.h"
#include "freq_table.h"

void encode_file(char *input_filename, char *output_filename, char *codes[]);
void decode_file(char *input_filename, char *output_filename, Node *root);

#endif // ENCODE_DECODE_H