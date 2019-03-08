#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define BYTES_IN_WORD_64BIT 8


extern void * addresses[10];
extern int addr_index;

void write(void * allocated, int words_allocated);
