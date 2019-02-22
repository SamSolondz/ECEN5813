#include "displaymem.h"

void displaymem()
{

  for(int j = 0; j < addr_index; j++)
  {
      printf("Address: %p Data: %#08lX\n", addresses[j], *((unsigned long *)addresses[j]));
  }
  return;
}
