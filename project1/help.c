#include "help.h"

void help()
{
	printf("---Commands available---\n");
	printf("'Allocate' memory\t\t Allocate a block of memory. User specifies the number of bytes or words to be allocated.\n");
	printf("'Free' memory\t\t Release the previously allocated block.\n");
	printf("'Display' memory words\t Display contents of memory in hex format. User may specify an address and the number of words to display.\n");
	printf("'Write' memory words\t User specifies an address to modify with a 32-bit value.\n");
	printf("'Invert' blocks\t\t Invert all memory bits in a specified area of memory. User specifies block.\n");
	printf("'Write pattern'\t\t Write a pseudo-random pattern in specified area of memory using specified seed value. User specifies address and length of memory.\n");
	printf("'Verify pattern'\t\t Verify a pseudo-random patter in specified area of memory using specified seed value. User specifies address and length of memory. \n\n");
	return;
}
