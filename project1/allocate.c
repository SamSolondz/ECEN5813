#include "allocate.h"

void * allocate(void * allocated)
{
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
	printf("Address of allocated memory: %p\n", new_allocated);   //show user address of allocated memory
	words_allocated += word_count;
	return new_allocated;
}
