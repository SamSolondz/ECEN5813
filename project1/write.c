#include "write.h"

extern int words_allocated;
extern int word_size;

void write(void * allocated, int words_allocated)
{
	// get specified address from user
	unsigned long * addr = 0;
	unsigned long val = 0;
	unsigned long read = 0;

	printf("(Write)\n");
	printf("Enter a hex address where you want the data saved (ex 0xf4ac23df).\n");
	if(allocated != 0)
		printf("Type '0' for the first allocated address.\n");


	scanf("%li", &read); //pointer to pointer
	if(read == 0)
		addr = (unsigned long *) allocated;
	else
		addr = (unsigned long *) read;

	for(int j = 0; j < words_allocated; j++)
	{
  		unsigned long * comp = (allocated + (unsigned long)(j * word_size));
    		if(addr == comp)
    		{
					printf("\nMaximum size for input data is %li.  \nIf input data exceeds maximum size, 0x7fffffffffffffff will be the input. \n\n", LONG_MAX);
					printf("Enter hex data (ex 0x15) \n");
      		scanf("%li", &val);

      		*addr = val;

    			printf("Data = %#lx written to address %p \n", *addr, addr);
      			return;
    		}
  }
	printf("Memory has not been allocated at that address!\n");
  return;
}
