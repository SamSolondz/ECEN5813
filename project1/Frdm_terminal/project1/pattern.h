#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "check_address.h"

extern int word_size;
extern int words_allocated;

void pattern(void * allocated, int sel);
