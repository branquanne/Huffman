#include "huffman.h"
#include <stdio.h>

int main(int argc, char **argv) {

  // Validera körningsträngen
  // Hej
  // What
  char *option = argv[1];
  char *file0 = argv[2];
  char *file1 = argv[3];
  char *file2 = argv[4];
  int hej = 10;

  if (argc != 5) {
    // aa
    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie -> skapa
    // huffmantabell -> encode (okomprimerad blir komprimerad)
    //
    // Validera input -> Frekvensanalys (file0) -> skapa huffman trie  ->
    // decode (komprimerad återställs till original)
  }
}
