#include "allocate.h"

void * allocate(void * allocated, int words_allocated)
{
	printf("Enter the number of words you would like to allocate: ");
	char word_read[3];
	scanf("%s", word_read); 	//TODO: protect against user input that is too long.
	int word_count = atol(word_read);

	int new_size = (words_allocated * BYTES_IN_WORD_64BIT) + (word_count * BYTES_IN_WORD_64BIT);
	void * new_allocated = (void *) realloc(allocated, new_size);
	printf("Address of allocated memory: %p\n", new_allocated);   //show user address of allocated memory
	if(new_allocated == NULL)
	{
		printf("Memory could not be allocated.\n");
		return NULL;
	}
	//printf("%c\n", *memPtr);
	return new_allocated;
}
