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
  if(read == 0)
  {
    return;
  }

  addr = (unsigned long *) read;
  for(int j = 0; j < addr_index; j++){
    if(addr == addresses[j])
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
