#include "huffman.h"
#include "bit_buffer.h"
#include "freq_table.h"
#include "pqueue.h"
#include "validate_data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* G*/

int main(int argc, char **argv) {

    // Validera körningsargument (kan bryta ut till egen funktion)
    checkNumberOfArguments(argc);
    checkOptionValidity(argv);

    char *option = argv[1];
    char *file0 = argv[2];
    char *file1 = argv[3];
    char *file2 = argv[4];

    // Load file in array byte-wise
    char *fileContents = loadFileCharacters(file0);

    // freq_tbale
    int *freq_table = checkFrequency(fileContents);

    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie -> skapa
    // huffmantabell -> encode (okomprimerad blir komprimerad)
    //
    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie  ->
    // decode (komprimerad återställs till original)

    free(freq_table);
    free(fileContents);

    return 0;
}
