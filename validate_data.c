#include "validate_data.h"
#include <stdio.h>
#include <string.h>


bool validate_args(int argc, char *argv[]) {
	if (argc != 5) {
	  fprintf(stderr, "Usage: %s -encode|-decode <frequency_file> <input_file> <output_file>\n", argv[0]);
	  return false;
	}
  
	if (strcmp(argv[1], "-encode") != 0 && strcmp(argv[1], "-decode") != 0) {
	  fprintf(stderr, "Usage: %s -encode|-decode <frequency_file> <input_file> <output_file>\n", argv[0]);
	  return false;
	}
	return true;
  }