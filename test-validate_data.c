#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

	char *fileName = "balenPaEkeby_GostaBerlingsSaga_SelmaLagerlof.txt";
	char *fileContent = loadFileCharacters(fileName);
	
	printf("%s ", fileContent);		
	
  
	free(fileContent);
  
	return 0;
  }