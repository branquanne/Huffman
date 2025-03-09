#ifndef ENCODE_DECODE_H
#define ENCODE_DECODE_H

#include "bit_buffer.h"
#include "freq_table.h"
#include "trie.h"

void encode_file(char *input_filename, char *output_filename, char *codes[], long *input_size, long *output_size);
void decode_file(char *input_filename, char *output_filename, Node *root);

#endif // ENCODE_DECODE_H