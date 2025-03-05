#ifndef ENCODE_DECODE_H
#define ENCODE_DECODE_H

#include "common_headers.h"
#include "huffman_table.h"
#include "trie.h"

void endodeFile(char *fileToEncode, char *outFile, HuffmanTable *table);

void decodeFile(char *fileToDecode, char *outFile, TrieNode *root);

#endif // ENCODE_DECODE_H