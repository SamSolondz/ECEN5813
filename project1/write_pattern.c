#include "write_pattern.h"
void write_pattern(void * allocated)
{
  unsigned long seed = 0;
  unsigned long * addr = 0;
  unsigned long read = 0;
  unsigned num = 0;
  int pattern[num];
  clock_t timer;

  int *ptr = (int*) malloc(100 * sizeof(int));
  printf("(Write Pattern)\n\n");
  timer = clock();

  // get address, seed, and number in pattern
  printf("Enter a starting address to store pattern.\n");
  if(allocated != 0)
    printf("Type '0' for the first allocated address.\n");
  scanf("%li", &read); //pointer to pointer
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

  printf("Enter a seed value to generate the pattern.\n");
  scanf("%lu", &seed);
  printf("How many numbers would you to generate and store?\n");
  scanf("%u", &num);

  // print pattern start
  printf("Requested pattern: ");
  // determine random numbers and print pattern numbers
  pattern[0] = (int) seed;      //store the seed value so we can work off that
  for (int i=1; i<=num; i++)
  {
      pattern[i] = (2*pattern[i-1] + 0) % 9;  //use the last value for the new value
      printf("%d, ", pattern[i]);
      *(addr + (i-1)) = pattern[i];
  }
  timer = clock() - timer;
  double functionTiming = ((double)timer)/CLOCKS_PER_SEC;
  printf("\npatternWrite took %lf seconds to complete.\n", functionTiming);

  free(ptr);
}
