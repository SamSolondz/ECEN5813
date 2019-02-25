#include "freemem.h"

void * freemem(void * allocated)
{
  printf("(Free)\n");
  void * removed;

  //Make sure there is user allocated memory to free
  if(words_allocated > 0)
    removed = allocated + ((words_allocated-1) * word_size);
  else
  {
    printf("No user alllocated memory to free!\n");
    return allocated;
  }

//Free user allocated memory
  if(removed == allocated){
    free(allocated);
    allocated = 0;
    printf("Freed memory at address %p\n", removed);
    printf("User allocated stack is empty.\n");
    words_allocated--;
  }
  else
  {
    if(allocated != 0)
    {
      allocated = realloc(allocated, (words_allocated-1) * word_size);
      printf("Freed memory at address %p\n", removed);
      words_allocated--;
    }
  }
  return allocated;
}
