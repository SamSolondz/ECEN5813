#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "readin.h"

#ifdef LINUX
#include "frdm.h"
#endif


extern int word_size;
extern int words_allocated;

bool check_address(void * allocated, unsigned long * addr);
