#include "write.h"

void write()
{
	// get specified value and specified address from user
  unsigned long *addr = 0;
  unsigned long val = 0;
  unsigned long read = 0;

  printf("Enter a hex address where you want the data saved. (ex 0xf4ac23df) \nInput: ");
  //TODO: bounds checking
  scanf("%li", &read); //pointer to pointer
  addr = (unsigned long *) read;

	printf("Enter hex data (ex 0x15) \nInput: ");
  //TODO: bounds checking
	scanf("%li", &val);

  *addr = val;
	printf("Data = %li \n", val);
	printf("Address = %p\n", addr);
  if(addr == NULL)
  {
    printf("Memory not written\n");
    return;
  }
	printf("Data at address = %#08lX \n", *addr);
}
