#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "frdm.h"

extern int words_allocated;
extern int word_size;

void * allocate(void * allocated);
