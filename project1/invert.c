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
  printf("\n\r(Invert)");
  printf("\n\rEnter a hex address of memory to invert (ex 0xf4ac23df).\n\r");
  if(allocated != 0)
    printf("Type '0' for the first allocated address.\n\r");

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

  //checki for NULL pointer
  if(addr == NULL)
  {
      printf("\n\rData could not be inverted at the specified address.");
      return;
  }
  // invert data
  *addr = ~(*addr);

  // print data
  #ifdef FRDM
  printf("\n\rInverted Data: %d", (int)*addr);
  #else
  printf("\n\rInverted Data: %#018lx", *addr);
  #endif

  timer = clock() - timer;
  double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds

  printf("\n\rProgram took %f seconds to execute", time_taken);
  return;
}
