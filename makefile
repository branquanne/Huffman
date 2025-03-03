CC = gcc
CFLAGS = -Wall -std=c99
TEST_HEADERS = validate_data.h freq_table.h
HEADERS = huffman.h $(TEST_HEADERS)

test_validate: test_validate_data.c validate_data.c $(TEST_HEADERS)
	$(CC) $(CFLAGS) -o test_validate test_validate_data.c validate_data.c

test_freq: test_freq_table.c freq_table.c validate_data.c $(TEST_HEADERS)
	$(CC) $(CFLAGS) -o test_freq test_freq_table.c freq_table.c validate_data.c

test_trie: test_trie.c trie.c freq_table.c validate_data.c $(HEADERS)
	$(CC) $(CFLAGS) -o test_trie test_trie.c trie.c freq_table.c validate_data.c

huffman: huffman.c freq_table.c validate_data.c $(HEADERS)
	$(CC) $(CFLAGS) -o huffman huffman.c freq_table.c validate_data.c