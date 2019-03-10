#include "freemem.h"

void * freemem(void * allocated)
{
  printf("\n\r(Free)");
  void * removed;

  //Make sure there is user allocated memory to free
  if(words_allocated > 0)
    removed = allocated + ((words_allocated-1) * word_size);
  else
  {
    printf("\n\rNo user allocated memory to free!\n");
    return allocated;
  }

//Free user allocated memory
  if(removed == allocated){
    free(allocated);
    allocated = 0;
    printf("\n\rFreed memory at address %p", removed);
    printf("\n\rUser allocated stack is empty.");
    words_allocated--;
  }
  else
  {
    if(allocated != 0)
    {
      allocated = realloc(allocated, (words_allocated-1) * word_size);
      printf("\n\rFreed memory at address %p", removed);
      words_allocated--;
    }
  }
  return allocated;
}
