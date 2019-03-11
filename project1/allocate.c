#include "allocate.h"

void * allocate(void * allocated)
{
	printf("\n\r(Allocate)");
	printf("\n\rEnter the number of words you would like to allocate:\n\r");
	char word_read[20];

	#ifdef FRDM
		readin(word_read, sizeof(word_read));
	#else
		scanf("%s", word_read);
	#endif

	int word_count = atol(word_read);
	void * new_allocated = 0;

	int new_size = (words_allocated * word_size) + (word_count * word_size);

	if(allocated == 0)
		new_allocated = (void *) malloc(new_size);
	else
		new_allocated = (void *) realloc(allocated, new_size);

	if(new_allocated == NULL)
	{
		printf("\n\rMemory could not be allocated.\n");
		return NULL;
	}
	#ifdef FRDM
		printf("\n\rAddress of allocated memory: 0x%p\n", new_allocated);   //show user address of allocated memory
	#else
		printf("\n\rAddress of allocated memory: %p\n", new_allocated);   //show user address of allocated memory
	#endif
	words_allocated += word_count;
	return new_allocated;
}
