#include "displaymem.h"

void displaymem(void * allocated)
{
  unsigned long * addr = 0;
  unsigned long read = 0;
  int numWords = 0;

  // get address
  printf("\n\r(Display)");
  printf("\n\rEnter the starting address of the data to display in hex.");
  if(allocated != 0)
    printf("\n\rType '0' to start from the first user allocated memory address.\n\r");

  printf("\n\r");

#ifdef FRDM
  char read_char[20];
  readin(read_char, sizeof(read_char));
  read = strtol(read_char, NULL, 16);
#else
	scanf("%li", &read);
#endif

  if(read == 0)
    addr = (unsigned long *) allocated;
  else
    addr = (unsigned long *) read;

  //Check if address is within allocated memory
  bool abort = check_address(allocated, addr);
  if(abort == true)
  	return;

  // get number of words
  printf("\n\rYou've allocated %d words. Enter the number of words you wish to display:\n\r", words_allocated);

#ifdef FRDM
  readin(read_char, sizeof(read_char));
  numWords = strtol(read_char, NULL, 16);
#else
	scanf("%d", &numWords);
#endif
  // print data
  for(int i = 0; i < numWords; i++)
  {
      if((addr + i) == NULL)
        printf("\n\rCannot display memory at 0x%p.", addr + i);
      else
      {
        #ifdef FRDM
          printf("\n\rAddress: 0x%p & Data: %d\n", addr + i, (int)*(addr + i));
        #else
          printf("\n\rAddress: %p & Data: %#018lx\n", addr + i, *(addr + i));
        #endif
      }

  }
  return;
}
