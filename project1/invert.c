#include "invert.h"

void invert()
    // use XOR to invert all memory bits in specified area of memory
    //(address and number of 32-bit words).  Also report time to perform op.
{
    // get specified address from user
    unsigned int *address = 0;
    unsigned int data[] = {1,2,3,7,0,9};
    int s = sizeof(data) / sizeof(int);
    unsigned int inverted[s];
    int last = sizeof(data) / sizeof(data[0]);
    int len = last;

	printf("Enter a 32 bit hex address without \"0x\" that you want to invert: \n");
	scanf("%p", &address);

//	if( ((*addr <= '0') || (*addr >= '9')) || ((*addr <= 'a') || (*addr >= 'f')) )
    {
//	    printf("\nYou need to enter in hex.\n\n");
	}

    *(int*)&address = data[0];	

//	printf("len: %d\n", len);
//	printf("last: %d\n", last);
	printf("address: %p\n", &address);
	
	// print original data
	printf("data in address = 0x");
	for (int i = 0; i < len; i++) 
    { 
        data[i];
        printf("%X", data[i]);
    } 
    printf("\n");
    
    // invert and print inverted data
    printf("data in inverted: 0x");
    for (int i = 0; i < len; i++) 
    { 
        inverted[i] = data[last];
        last--;
        printf("%X", inverted[i]);
    } 
        printf("\n\n");
}

int main()
{
    // calculate function time (geeksforgeeks.org)
	clock_t timer; 
    timer = clock(); 
    invert(); 
    timer = clock() - timer; 
    double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds 
  
    printf("program took %f seconds to execute \n", time_taken); 
}
