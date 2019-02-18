#include "write.h"

int write()
{   
	// get specified value and specified address from user
    unsigned int *addr = 0; 
    unsigned int val = 0;

	printf("Enter a 32-bit hex address without \"0x\" where you want the data saved. (ex f4ac23df): \n");
	scanf("%p", &addr);
	
//	if( ((*addr <= '0') || (*addr >= '9')) || ((*addr <= 'a') || (*addr >= 'f')) )
    {
//	    printf("\nYou need to enter in hex.\n\n");
	}
	
	printf("Enter a 32-bit hex data without \"0x\" you want to save: \n");
	scanf("%x", &val);
	
//	if( ((*addr <= '0') || (*addr >= '9')) || ((*addr <= 'a') || (*addr >= 'f')) )
    {
//	    printf("\nYou need to enter in hex.\n\n");
	}

    *(int*)&addr = val;	
	
	printf("Data = 0x%X \n", val);
	printf("Address = %p\n", &addr);
	printf("Data at address = 0x%X \n", addr);
}
