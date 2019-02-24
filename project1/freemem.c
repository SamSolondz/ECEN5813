#include "freemem.h"

void * freemem(void * allocated)
{
  void * removed = allocated + ((words_allocated-1) * word_size);

  if(removed == allocated){
    free(allocated);
    printf("Freed memory at address %p\n", removed);
    printf("User allocated stack is empty.\n");
    words_allocated--;
  }
  else
  {
    allocated = realloc(allocated, (words_allocated-1) * word_size);
    if(allocated != 0)
    {
      printf("Freed memory at address %p\n", removed);
      words_allocated--;
    }
    else
      printf("Could not free memory at address %p\n", removed);
  }
}
