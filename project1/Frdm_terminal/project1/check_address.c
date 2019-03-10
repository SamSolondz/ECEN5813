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
    	printf("Warning: Memory has not been allocated at that address.\nDo you wish to proceed? (y/n)\n");
  	  char response;
  		scanf(" %c", &response); //pointer to pointer
      switch (response)
      {
    	  case 'y':
          return false;
          break;
  			case 'n':
  			default:
  			   printf("Operation aborted.\n");
    			 return true;
           break;
  		}
    }
    return false;
}
