#include "pattern.h"
void pattern(void * allocated, int sel) //write_pattern: sel = 0;
{                                             //verify_pattern: sel = 1;
  unsigned long seed = 0;
  unsigned long * addr = 0;
  unsigned long read = 0;
  int pattern_len = 0;
  double functionTiming;
  clock_t timer;

  // get address, seed, and number in pattern

  switch (sel) {
    case 0:         //write Pattern
      printf("(Write Pattern)\n\n");
      printf("Enter a starting address to store the pattern.\n");
      break;
    case 1:         //write Pattern
      printf("(Verify Pattern)\n\n");
      printf("Enter a starting address to verify the pattern.\n");
      break;
    default:
      printf("Pattern error\n");
      return;
  }

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

  printf("Enter a seed value to generate the pattern.\n");
  scanf("%lu", &seed);

  if(sel == 0)
    printf("How many numbers would you like to generate and store?\n");
  else
    printf("How many addresses would you like to check?\n");

  scanf("%d", &pattern_len);
  int pattern[pattern_len+1];


  printf("Generated pattern: ");
  // determine random numbers and print pattern numbers
  timer = clock();              //start counting here since we want to time the operation
  pattern[0] = (int) seed;      //store the seed value so we can work off that
  int c = 0;
  int module = 27;

  if(seed == 0)
      c = 5;

  for (int i=0; i<pattern_len; i++)
  {
      if((2*pattern[i] + c) == 27)
	  c = 11;

      pattern[i+1] = (2*pattern[i] + c) % module;  //use the last value for the new value
      printf("%d", pattern[i+1]);
      if(i != pattern_len-1)
	printf(", ");
      if(sel == 0)                           //write only on write_pattern;
        *(addr + i) = pattern[i+1];
  }

  if(sel == 0)                  //write_pattern is done
    timer = clock() - timer;
  else
  {                      //check the generated pattern against memory
    int actual[pattern_len];
    bool valid_pattern = true;
    for(int j = 0; j < pattern_len; j++)
    {
      actual[j] = *(int *)(addr+j);
      if(actual[j] != pattern[j+1])
        valid_pattern = false;
    }

    if(valid_pattern == false)
    {
      printf("\nPattern is not valid!\nValues found:\n");
      for(int j = 0; j < pattern_len; j++)
      {
        printf("Address: %p & Data: %d; Expected Value: %d", addr + j, actual[j], pattern[j+1]);
      }

    }
    else
      printf("\nPattern is valid!");

    timer = clock() - timer;      //verify_pattern is done
  }

  functionTiming = ((double)timer)/CLOCKS_PER_SEC;
  printf("\nwrite_pattern took %lf seconds to complete.\n", functionTiming);

}
