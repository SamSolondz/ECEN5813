#include "help.h"

void help()
{
	printf("(Help)\n");
	printf("---Commands available---\n");
	printf("'Allocate' memory\t Allocate a block of memory. User specifies the number of or words to be allocated.\n");
	printf("'Free' memory\t\t Release the previously allocated block.\n");
	printf("'Display' memory words\t Display a block of memory in hex format. User may specify an address and the number of words to display.\n");
	printf("'Write' memory words\t User specifies an address to modify.\n");
	printf("'Invert' blocks\t\t Invert all memory bits in a specified area of memory. User specifies block.\n");
	printf("'Pattern'\t\t Write a pseudo-random pattern in specified area of memory using specified seed value. User specifies address and length of memory.\n");
	printf("'Verify'\t Verify a pseudo-random patter in specified area of memory using specified seed value. User specifies address and length of memory. \n\n");
	return;
}
