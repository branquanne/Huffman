# Huffman

> A from-scratch Huffman coding project in C99, focused on the data structures and bit-level operations behind lossless compression.

[![Language](https://img.shields.io/badge/language-C99-00599C?logo=c)](https://en.cppreference.com/w/c/language)
[![Build](https://img.shields.io/badge/build-Make-427819?logo=gnu)](https://www.gnu.org/software/make/)

## Overview

This project explores how a Huffman compressor is built from the ground up:

1. Read an input file as raw bytes.
2. Count the frequency of each possible byte value.
3. Use a priority queue to build the Huffman tree.
4. Represent compressed data at the bit level.
5. Encode and decode files without losing information.

The current implementation includes the input-validation and frequency-analysis foundation, plus reusable list, priority-queue, and bit-buffer modules. The complete tree-building and file encode/decode pipeline is the next stage of development.

## Why this project stands out

- **Low-level systems programming:** manual memory management, pointers, dynamic allocation, and binary file I/O.
- **Algorithmic thinking:** the project is structured around the greedy Huffman-coding algorithm.
- **Data-structure design:** a doubly linked list powers a generic priority queue.
- **Bit manipulation:** the bit buffer supports insertion, inspection, removal, dynamic growth, and byte conversion.
- **Modular C code:** functionality is separated into focused `.c`/`.h` modules with small demonstration programs.

## Repository structure

| File | Responsibility |
| --- | --- |
| `huffman.c`, `huffman.h` | Command-line entry point and Huffman workflow |
| `validate_data.c`, `validate_data.h` | Argument validation and binary file loading |
| `freq_table.c`, `freq_table.h` | 256-entry byte-frequency analysis |
| `bit_buffer.c`, `bit_buffer.h` | FIFO bit-level storage and byte conversion |
| `pqueue.c`, `pqueue.h` | Generic priority queue |
| `list.c`, `list.h` | Doubly linked list used by the priority queue |
| `test_*.c` | Focused demonstrations and checks for individual modules |
| `makefile` | Build targets |

## Requirements

- GCC or another C99-compatible compiler
- GNU Make
- macOS or Linux

## Build

Build the current command-line program:

```bash
make huffman
```

Build the validation and frequency-analysis checks:

```bash
make test_validate
make test_freq
```

The repository also includes standalone demonstrations for the bit buffer and priority queue:

```bash
gcc -Wall -std=c99 -o test_bit_buffer bit_buffer.c test_bit_buffer.c
gcc -Wall -std=c99 -o test_pqueue list.c pqueue.c test_pqueue.c
```

## Usage

The command-line interface expects an operation and three file paths:

```bash
./huffman -encode <input-file> <compressed-file> <metadata-file>
./huffman -decode <compressed-file> <metadata-file> <output-file>
```

At the current stage, the program validates the command-line shape, loads the first file, and creates its byte-frequency table. The actual serialization, Huffman-tree construction, encoding, and decoding steps are actively being developed.

## Technical design

### Frequency analysis

`checkFrequency` creates a table with 256 counters, one for each possible byte value. Input is loaded in binary mode so the analysis can work with arbitrary byte-oriented files rather than only text.

### Bit buffer

The bit buffer provides a FIFO abstraction over dynamically growing storage:

- insert or remove one bit;
- insert or remove one byte;
- inspect a bit without removing it;
- convert buffered bits to a byte array with zero padding.

This is the foundation for writing Huffman codes that do not align to byte boundaries.

### Priority queue and list

The priority queue accepts a caller-provided comparison function, making it reusable for Huffman tree nodes and other prioritized values. Its linked-list implementation keeps the queue generic and separates container behavior from element ownership.

## Development notes

This is an educational and portfolio project intended to demonstrate algorithm implementation and C fundamentals. Planned improvements include:

- initialize and validate frequency-table allocation;
- build the Huffman tree from non-zero frequencies;
- generate canonical code paths;
- serialize tree metadata and encoded bits;
- implement round-trip encode/decode tests;
- improve error reporting and resource cleanup;
- add automated tests to the Makefile.

## Learning outcomes

Working on this project develops practical experience with:

- C99 compilation and warnings;
- API design across header/source boundaries;
- pointers, structs, callbacks, and ownership;
- linked data structures;
- greedy algorithms and binary trees;
- binary file formats and bit-level serialization;
- testing small modules independently before integrating them.

## License and attribution

Project code is authored by Henrik Röjvall and Bran Quanne, with educational support code attributed in the source files to Jonny Pettersson and other original authors. See the relevant source headers for the original attribution and usage terms of included course material.

