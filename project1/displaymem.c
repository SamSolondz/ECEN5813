#include "displaymem.h"

void displaymem()
{
  void * addr = 0;
  unsigned long read = 0;
  unsigned long numWords = 0;

  // get address
  printf("Enter the starting address of the data to display (ex 0xffffffff): \n");
  scanf("%lu", &read);
  addr = (void * ) read;

  // get number of words
  printf("Enter the number of 32-bit words to display: \n");
  scanf("%lu", &numWords);

  // print data
  for(int i = 0; i < numWords; i++)
  {
      printf("Address: %p & Data: %#08lX\n", addr + i, *(addr + i);
  }
  return;
}
