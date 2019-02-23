#include "invert.h"

void invert()
    // invert all memory bits in specified area of memory
    // report time to perform op.
{
  clock_t timer; 
  timer = clock(); 
  unsigned long *address = 11215;    // test data... switch back to 0
  unsigned long numWords = 0;
  unsigned long size = 0;

  // get address
  printf("Enter the address of the data to invert (ex 0xffffffff): \n");
  scanf("%li", &address);

  size = sizeof(addr)*sizeof(long);

  // invert data
  *address = ~(*address);      
    
  // print data
  printf("Inverted Data: %#08lX\n", address);

  timer = clock() - timer; 
  double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds 
  
    printf("program took %f seconds to execute \n", time_taken); 
}
