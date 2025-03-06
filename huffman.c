#include "huffman.h"
#include "bit_buffer.h"
#include "encode_decode.h"
#include "freq_table.h"
#include "pqueue.h"
#include "validate_data.h"
/* G*/

int main(int argc, char **argv) {

  // Validera körningsargument (kan bryta ut till egen funktion)
  validateData(argc, argv);

  char *option = argv[1];
  char *file0 = argv[2];
  char *file1 = argv[3];
  char *file2 = argv[4];

  if (strcmp(option, "-encode")) {
    // encode
    encodeFile(file0, file1, file2);
  } else if (strcmp(option, "-decode")) {
    // decode
    decodeFile(file1, file2, root);
  }
  



  // Validera input -> Frekvensanalys (file0) -> skapa huffman trie -> skapa
  // huffmantabell -> encode (okomprimerad blir komprimerad)
  //
  // Validera input -> Frekvensanalys (file0) -> skapa huffman trie  ->
  // decode (komprimerad återställs till original)

  free(freq_table);
  free(fileContents);

  return 0;
}

void validateData(int argc, char **argv) {

  for (int i = 2; i < argc; i++) {
    checkInFile(argv[i]);
  }

  if (checkNumberOfArguments(argc) == false) {
    printf(stderr, "Invalid number of arguments\n");
    exit(1);
  }

  if (checkOptionValidity(argv) == false) {
    printf(stderr, "Invalid option\n");
    exit(1);
  }
}