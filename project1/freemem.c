#include "freemem.h"

int freemem()
{
  void * addr;
  unsigned long read = 0;
  printf("Enter the address of the block of memory you would like to free:\nInput: ");
  scanf("%li", &read);
  addr = (void *) read;
  free(addr);
  return 0;
}
