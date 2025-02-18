#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
/* G*/

int main(int argc, char **argv) {

  // Validera körningsargument (kan bryta ut till egen funktion)
  char *option = argv[1];
  char *file0 = argv[2];
  char *file1 = argv[3];
  char *file2 = argv[4];

  if (argc != 5) {
    // aa

    printf("Usage: %s <option> <file0> <file1> <file2>\n", argv[0]);
    exit(1);

    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie -> skapa
    // huffmantabell -> encode (okomprimerad blir komprimerad)
    //
    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie  ->
    // decode (komprimerad återställs till original)
  }

  return 0;
}
