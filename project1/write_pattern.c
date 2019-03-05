#include "write_pattern.h"
void write_pattern()
{
  unsigned long seed = 0;
  //unsigned long * address = 0;
  unsigned num = 0;
  int pattern[num];
  clock_t timer;

  int *ptr = (int*) malloc(100 * sizeof(int));
  printf("address: %p\n", ptr);
  printf("(Write Pattern)\n\n");
  // get address, seed, and number in pattern
  timer = clock();
  // printf("What's the address where you would like to store the pattern?\n");
  // scanf("%li", address);
  printf("Enter a seed value to generate the pattern.\n");
  scanf("%lu", &seed);
  printf("How many numbers would you like generated?\n");
  scanf("%u", &num);
  // print pattern start
  printf("Requested pattern: ");

  // determine random numbers and print pattern numbers
  pattern[0] = (int) seed;      //store the seed value so we can work off that
  for (int i=1; i<=num; i++)
  {
      pattern[i] = (2*pattern[i-1] + 0) % 9;
      printf("%d, ", pattern[i]);
  }
  timer = clock() - timer;
  double functionTiming = ((double)timer)/CLOCKS_PER_SEC;
  printf("\npatternWrite took %lf seconds to complete.\n", functionTiming);

  free(ptr);
}
