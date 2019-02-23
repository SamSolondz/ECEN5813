#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define BYTES_IN_WORD_64BIT 8

extern int words_allocated;

void * allocate(void * allocated);
