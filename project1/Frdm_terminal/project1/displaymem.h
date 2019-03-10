#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "check_address.h"
extern void * addresses[10];

extern int words_allocated;
extern int word_size;

void displaymem(void * allocated);
