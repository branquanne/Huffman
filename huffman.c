#include "huffman.h"
#include "freq_table.h"
#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>
/* G*/

int main(int argc, char **argv) {

  // Validera körningsargument (kan bryta ut till egen funktion)
  char *option = argv[1];
  char *file0 = argv[2];
  char *file1 = argv[3];
  char *file2 = argv[4];

  // Validate input
  checkInputValidity(argc, argv);

  // Load file in array byte-wise
  char *fileContents = loadFileCharacters(file0);

  // freq_tbale
  int *freq_table = checkFrequency(fileContents);

  if (argc != 5) {
    // aa
    //

    printf("Usage: %s\n [OPTION] [FILE0] [FILE1] [FILE2]\n", argv[0]);
    printf("Options:\n");
    printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2");
    printf("-decode decodes FILE1 according to frequence analysis done on FILE0.Stores the result in FILE2");
    exit(1);

    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie -> skapa
    // huffmantabell -> encode (okomprimerad blir komprimerad)
    //
    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie  ->
    // decode (komprimerad återställs till original)
  }

  return 0;
}
