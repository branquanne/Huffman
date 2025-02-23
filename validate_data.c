#include "validate_data.h"
#include "huffman.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void checkNumberOfArguments(int numberOfArguments) {
    if (numberOfArguments != 5) {
        printf("Usage: %s\n [OPTION] [FILE0] [FILE1] [FILE2]\n", "huffman");
        printf("Options:\n");
        printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
        printf("-decode decodes FILE1 according to frequence analysis done on FILE0.Stores the result in FILE2\n");
        exit(1);
    }
}

void checkOptionValidity(char **arguments) {
    if (strcmp(arguments[1], "-encode") != 0 && strcmp(arguments[1], "-decode") != 0) {
        printf("Invalid option: %s\n", arguments[1]);
        exit(1);
    }
}

char *loadFileCharacters(char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *fileContent = malloc(fileSize + 1);
    if (fileContent == NULL) {
        printf("Could not allocate memory for file content\n");
        exit(1);
    }

    fread(fileContent, 1, fileSize, file);
    fileContent[fileSize] = '\0';
    fclose(file);

    return fileContent;
}
