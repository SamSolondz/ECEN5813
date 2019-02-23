#include "invert.h"

void invert()
    // invert all memory bits in specified area of memory
    // report time to perform op.
{
<<<<<<< HEAD
  clock_t timer; 
  timer = clock(); 
  unsigned long *address = 0;    // test data... switch back to 0
  unsigned long numWords = 0;
=======
  // calculate function time (geeksforgeeks.org)
  clock_t timer;
  timer = clock();

  unsigned long *addr = 0;    // test data... switch back to 0
  unsigned long read = 0;
>>>>>>> e975773a74e5caf689b8f1cb72e20e59429e63b6
  unsigned long size = 0;

  // get address
  printf("Enter the address of the data to invert (ex 0xffffffff): \nInput: ");
  scanf("%li", &read); //pointer to pointer
  if(read == 0)
  {
    printf("Memory at that address has not been allocated!\n");
    return;
  }

  addr = (unsigned long *) read;

  *addr = ~(*addr);

<<<<<<< HEAD
  // invert data
  *address = ~(*address);      
    
  // print data
  printf("Inverted Data: %#08lX\n", address);

  timer = clock() - timer; 
  double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds 
  
    printf("program took %f seconds to execute \n", time_taken); 
=======
  // print data
  printf("Inverted Data: %#016lx\n", *addr);
  timer = clock() - timer;
  double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds

  printf("Took %f seconds to execute invert \n", time_taken);
>>>>>>> e975773a74e5caf689b8f1cb72e20e59429e63b6
}
