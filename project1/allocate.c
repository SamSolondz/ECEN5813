#include "allocate.h"

char * allocate()
{
	printf("Enter the number of bytes you would like to allocate: ");
	char byte_read[3];
	scanf("%s", byte_read); 	//TODO: protect against user input that is too long.
	int byte_count = atol(byte_read);

	void * memPtr = (void *) malloc(byte_count * sizeof(uint8_t));
	printf("size %lu", sizeof(uint8_t));
	printf("Address of allocated memory: %X\n", memPtr);   //show user address of allocated memory
	if(ptr == NULL)
	{
		printf("Memory could not be allocated.\n");
		return NULL;
	}
	//printf("%c\n", *memPtr);
	return memPtr;
}
