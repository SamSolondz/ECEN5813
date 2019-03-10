#include "write.h"
extern int words_allocated;
extern int word_size;

void write(void * allocated, int words_allocated)
{
	// get specified address from user
	unsigned long * addr = 0;
	unsigned long val = 0;
	char read[20];

	printf("\n\r(Write)");
	printf("\n\rEnter a hex address where you want the data saved (ex 0xf4ac23df).\n\r");
	if(allocated != 0)
		printf("\n\rType '0' for the first allocated address.\n\r");


	readin(read, sizeof(read));
	val = strtol(read, NULL, 16);
	//scanf("%li", &read); //pointer to pointer
	if(val == 0)
		addr = (unsigned long *) allocated;
	else
		addr = (unsigned long *) val;

	//Check if address is within allocated memory
	bool abort = check_address(allocated, addr);
	if(abort == true)
		return;

	printf("\n\rMaximum size for input data is %li.\n\rIf input data exceeds maximum size, 0x7fffffffffffffff will be the input.", LONG_MAX);
	printf("\n\rEnter hex data (ex 0x15)\n\r");
	//scanf("%li", &val);
	readin(read, sizeof(read));
	val = strtol(read, NULL, 16);

//check for NULL pointer
	if(addr == NULL)
	{
		printf("Data could not be written to the specified address.\n");
		return;
	}
	*addr = val;
	printf("\n\rData = %d written to address %p\n",(int)*addr, addr);
  return;

}
