#include "check_address.h"

bool check_address(void * allocated, unsigned long * addr)
{
  void * test;          //create a pointer to test if the user-defined pointer is allocated
  int valid = false;
  for(int i = 0; i < words_allocated; i++)
  {
  	test = allocated + (i * word_size);
  	if(test == addr)
    	valid = true;
   }
   if(valid == false)
   {
	   printf("\n\rWarning: Memory has not been allocated at that address!\n\rDo you wish to proceed? (y/n)\n\r");
  	  char response[2];
	  #ifdef FRDM
  	  	  readin(response, sizeof(response));
	  #else
  	  	  scanf("%c", &response);
	  #endif
      if (!strcmp(response, "y") | !strcmp(response, "Y"))
    	  return false;
      else
      {
    	  printf("\n\rOperation aborted.\n\r");
    	  return true;
      }
   }
   return false;
}
