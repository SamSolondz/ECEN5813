#include "displaymem.h"

void displaymem()
{
  unsigned long * addr = 0;
  unsigned long read = 0;
  int numWords = 0;

  // get address
  printf("Enter the starting address of the data to display (ex 0xffffffff):\nInput: ");
  scanf("%li", &read);
  addr = (unsigned long * ) read;

  // get number of words
  printf("You've allocated %d words. Enter the number of words you wish to display \nInput: ", words_allocated);
  scanf("%d", &numWords);

  // print data
  for(int i = 0; i < numWords; i++)
  {
      printf("Address: %p & Data: %#016lx\n", addr + i, *(addr + i));
  }
  return;
}
