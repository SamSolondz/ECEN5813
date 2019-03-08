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

	//Check if address is within allocated memory
	bool abort = check_address(allocated, addr);
	if(abort == true)
		return;

	printf("\nMaximum size for input data is %li.  \nIf input data exceeds maximum size, 0x7fffffffffffffff will be the input. \n\n", LONG_MAX);
	printf("Enter hex data (ex 0x15) \n");
  scanf("%li", &val);
	*addr = val;
	printf("Data = %#lx written to address %p \n", *addr, addr);
  return;

}
