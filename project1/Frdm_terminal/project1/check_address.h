#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

extern int word_size;
extern int words_allocated;

bool check_address(void * allocated, unsigned long * addr);
