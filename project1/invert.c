#include "invert.h"

// invert all memory bits in specified area of memory
// report time to perform op.
void invert(void * allocated)
{
  // calculate function time (geeksforgeeks.org)
  clock_t timer;
  timer = clock();

  unsigned long *addr = 0;    // test data... switch back to 0
  unsigned long read = 0;

  // get address
  printf("(Invert)\n");
  printf("Enter a hex address of memory to invert (ex 0xf4ac23df)\n");
  if(allocated != 0)
    printf("Type '0' for the first allocated address.\n");

  scanf("%li", &read); //pointer to pointer
  if(read == 0)
    addr = (unsigned long *) allocated;
  else
    addr = (unsigned long *) read;

  //Check if address is within allocated memory
  bool abort = check_address(allocated, addr);
  if(abort == true)
  	return;

  // invert data
  *addr = ~(*addr);

  // print data
  printf("Inverted Data: %#016lx\n", *addr);

  timer = clock() - timer;
  double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds

  printf("Program took %f seconds to execute \n", time_taken);
  return;
}
