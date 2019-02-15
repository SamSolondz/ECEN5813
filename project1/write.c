#include "write.h"

int write(unsigned int *address, unsigned int value);

int main()
{
    // get specified value and specified address from user
    unsigned int *addr; 
    unsigned int val;

	printf("Enter a 32 bit hex address without \"0x\" where you want the data saved: \n");
	scanf("%x", &addr);
	
//	if(!isxdigit(&address))
    {
//	    printf("\nYou need to enter in hex.\n\n");
//	    printf("Enter a 32 bit hex address without \"0x\" where you want the data saved: \n");
//	    scanf("%x", &address);
	}
	
	printf("Enter a 32 bit hex data without \"0x\" you want to save: \n");
	scanf("%x", &val);
	
//	if(!isxdigit(&value))
	{
//	    printf("\nYou need to enter in hex.\n\n");
//	    printf("Enter a 32 bit hex data without \"0x\" you want to save: \n");
//	    scanf("%x", &value);
	}
	printf("Data = 0x%X \n", val);
	printf("Address = 0x%X \n", addr);

    int ret = write(addr, val);
}

// function to write a specified value to a specified address
int write(unsigned int *address, unsigned int value)
{
    int *addrPtr = address;
    *addrPtr = value;
    
    printf("*addr: %x\n", addrPtr);
}
