#include "displaymem.h"

void displaymem(void * allocated)
{
  unsigned long * addr = 0;
  unsigned long read = 0;
  int numWords = 0;

  // get address
  printf("(Display)\n");
  printf("Enter the starting address of the data to display in hex.\n");
  if(allocated != 0)
    printf("Type '0' to start from the first user allocated memory address.\n");

  scanf("%li", &read);
  if(read == 0)
    addr = (unsigned long *) allocated;
  else
    addr = (unsigned long *) read;

//Check that address is within allocated memory
  void * test;
  int valid = false;
  for(int i = 0; i < words_allocated; i++)
  {
    test = allocated + (i * word_size);
    if(test == addr)
      valid = true;
  }
  if(valid == false)
  {
    printf("Memory has not been allocated at that address!\n");
    return;
  }

  // get number of words
  printf("You've allocated %d words. Enter the number of words you wish to display:\n", words_allocated);
  scanf("%d", &numWords);

  // print data
  for(int i = 0; i < numWords; i++)
  {
      if((addr + i) == NULL)
        printf("Cannot display memory at %p.\n", addr + i);
      else
        printf("Address: %p & Data: %#016lx\n", addr + i, *(addr + i));
  }
  return;
}
