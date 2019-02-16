#include "invert.h"

int invert()
    // use XOR to invert all memory bits in specified area of memory
    //(address and number of 32-bit words).  Also report time to perform op.
{    
    // get specified address from user
    unsigned int *address;
    unsigned int *destination;
    int len = sizeof(address);
    *address = 0xffffffffffffffffffffffff4444444444444444444444444aaaaaaaaaaaaaaaa5555555553;

//	printf("Enter a 32 bit hex address without \"0x\" that you want to invert: \n");
//	scanf("%x", &address);
	printf("address:%p\n", &address);

	printf("address0:%d\n", address[0]);
	printf("address1:%d\n", address[1]);

//	if( (((addr |= 0x20) >= '0') && (addr <= '9')) || ((addr >= 'a') && (addr <= 'f'))  )
    {
//	    printf("\nYou need to enter in hex.\n\n");
//	    printf("Enter a 32 bit hex address without \"0x\" where you want the data saved: \n");
//	    scanf("%x", &address);
	}

    for(int i = 0; i < len; i++)	
    {
        destination[i] ^= address[i];
    }

	printf("Destination = %d \n", destination);
}