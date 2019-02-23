#include "write.h"


void write(void * allocated, int words_allocated)
{
	// get specified value and specified address from user
  unsigned long *addr = 0;
  unsigned long val = 0;
  unsigned long read = 0;

  printf("Enter a hex address where you want the data saved. (ex 0xf4ac23df) \nInput: ");
  //TODO: bounds checking
  scanf("%li", &read); //pointer to pointer
  if(read == 0)
  {
    return;
  }
  addr = (unsigned long *) read;
  for(int j = 0; j < words_allocated; j++){
    unsigned long *comp = (allocated + (words_allocated * BYTES_IN_WORD_64BIT));
    if(*addr == *comp)
    {
      printf("Enter hex data (ex 0x15) \nInput: ");
      scanf("%li", &val); //TODO: bounds checking


      *addr = val;
    	printf("Data = %li \n", val);
    	printf("Address = %p\n", addr);

    	printf("Data at address = %#08lX \n", *addr);
      return;
    }
  }
  printf("Memory has not been allocated at that address!\n");
  return;

}
