#include "help.h"

void help()
{
	printf("\n\r(Help)");
	printf("\n\r---Commands available---");
	printf("\n\r'Allocate'\t\t Allocate a block of memory. User specifies the number of words to be allocated.\n");
	printf("\r'Free'\t\t\t Release the previously allocated block of memory.\n");
	printf("\r'Display'\t\t Display a block of memory in hex format. User specifies an address and number of words to display.\n");
	printf("\r'Write'\t\t\t User specifies an address to modify and data to write to that address.\n");
	printf("\r'Invert'\t\t Invert all memory bits at a specified memory address.\n");
	printf("\r'Pattern'\t\t Write a pseudo-random pattern of a specified length at a specified memory address using a specified seed value.\n");
	printf("\r'Verify'\t\t Verify a pseudo-random pattern of a specified length at a specified memory address using a specified seed value.\n\n");
	return;
}
