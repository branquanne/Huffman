#include "freq_table.h"
#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char *fileName = "balenPaEkeby_GostaBerlingsSaga_SelmaLagerlof.txt";
	char *fileContent = loadFileCharacters(fileName);
	int *freq_table = checkFrequency(fileContent);

	for (int i = 0; i < 256; i++) {
		if (freq_table[i] != 0) {
			printf("%c: %d\n", i, freq_table[i]);
		}
	}

	free(fileContent);
	free(freq_table);

	return 0;	
}