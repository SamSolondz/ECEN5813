#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#define BYTES_IN_WORD_64BIT 8

extern int words_allocated;
extern int word_size;
extern void * addresses[10];
extern int addr_index;

int test(){
FILE *f = fopen("testOut.txt", "w");
if(f == NULL)
{
	printf("Error opening file\n");
	exit(1);
}

// test allocate
	printf("Enter the number of words you would like to allocate: ");
	char word_read[3];
	scanf("%s", word_read); 	
	
	int word_count = atol(word_read);

	void * new_allocated = 0;

	int new_size = (words_allocated * word_size) + (word_count * word_size);

	if(allocated = 0)
		new_allocated = (void *) malloc(new_size);
	else
		new_allocated = (void *) realloc(allocated, new_size);

	if(new_allocated == NULL)
	{
		printf("Memory could not be allocated.\n");
		return NULL;
	}
	fprintf(f, "Address of allocated memory: %p\n", new_allocated);   //show user address of allocated memory
	words_allocated += word_count;

// test write
	// get specified address from user
	unsigned long * addr = 0;
	unsigned long val = 0;
	unsigned long read = 0;

	printf("Enter a hex address where you want the data saved. (ex 0xf4ac23df) \nInput: ");

	scanf("%li", &read); //pointer to pointer
	if(read == 0)
	{
		printf("Invalid input\n");
		return;
	}

	// get specified value from user
	addr = (unsigned long *) read;
	for(int j = 0; j < words_allocated; j++)
	{
  		unsigned long * comp = (allocated + (unsigned long)(j * word_size));
    		if(addr == comp)
    		{
			printf("\nMaximum size for input data is %li.  \nIf input data exceeds maximum size, 0x7fffffffffffffff will be the input. \n\n", LONG_MAX);    
			printf("Enter hex data (ex 0x15) \nInput: ");
      			scanf("%li", &val); 

      			*addr = val;

    			fprintf(f, "Data = %#lx written to address %p \n", *addr, addr);
      			return;
    		}
  	}
  	printf("Memory has not been allocated at that address!\n");
  
// test display
	unsigned long * addr = 0;
	unsigned long read = 0;
	int numWords = 0;

	// get address
	printf("Enter the starting address of the data to display (ex 0xffffffff):\nInput: ");
	scanf("%li", &read);
	addr = (unsigned long * ) read;

	// get number of words
	fprintf(f, "You've allocated %d words. Enter the number of words you wish to display \nInput: ", words_allocated);
	scanf("%d", &numWords);

	// print data
	for(int i = 0; i < numWords; i++)
	{
		fprintf(f, "Address: %p & Data: %#016lx\n", addr + i, *(addr + i));
	}
	
// test invert
	// calculate function time (geeksforgeeks.org)
	clock_t timer;
	timer = clock();

	unsigned long *addr = 0;    // test data... switch back to 0
	unsigned long read = 0;

	// get address
	printf("Enter the address of the data to invert (ex 0xffffffff): \nInput: ");
	scanf("%li", &read); //pointer to pointer
	if(read == 0)
	{
		printf("Memory at that address has not been allocated!\n");
		return;
	}

	addr = (unsigned long *) read;
	
	// invert data
	*addr = ~(*addr);

	// print data
	fprintf(f, "Inverted Data: %#016lx\n", *addr);

	timer = clock() - timer;
	double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds

	printf("Program took %f seconds to execute \n", time_taken);
	
// test free
	void * removed = allocated + ((words_allocated-1) * word_size);

	if(removed == allocated){
		free(allocated);
		fprintf(f, "Freed memory at address %p\n", removed);
		printf("User allocated stack is empty.\n");
		words_allocated--;
	}
	else
	{
		allocated = realloc(allocated, (words_allocated-1) * word_size);
		if(allocated != 0)
		{
		fprintf(f, "Freed memory at address %p\n", removed);
		words_allocated--;
		}
		else
		printf("Could not free memory at address %p\n", removed);
	}
	fclose(f);
}