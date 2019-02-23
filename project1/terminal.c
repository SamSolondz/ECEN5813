#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "help.h"
#include "allocate.h"
#include "write.h"
#include "freemem.h"
#include "displaymem.h"
#include "invert.h"

//#define BYTES_IN_WORD_64BIT  8

int main(void)
{

	void * allocated = malloc(1 * sizeof(*allocated));	//pointer to allocated memory
	int size = 1 * sizeof(*allocated);		//returns size in bytes
	printf("size: %lu\n", sizeof(allocated));

	int words_allocated = 0;


	bool exit = false;
	while(exit == false)
	{
		printf("\n------------------------------------------------------------------\n");
		printf("Enter a command. Type 'Help' to get a list of commands. Type 'Exit' to quit.\n");
	  char command[16];
		printf("Command: ");
	        scanf("%15s", command); 	//TODO: protect against a user input that is too long.
		if(sizeof(command) > 20)
		{
			printf("\nCommand not recognized, try again\n");
		}
		else if(!strcmp(command, "help") | !strcmp(command, "Help"))
		{
			help();
		}
		else if(!strcmp(command, "allocate") | !strcmp(command, "Allocate"))
		{
			void * new_alloc = allocate();
			size = size + sizeof(*allocated);
			allocated = realloc(allocated, size);	//make room for more blocks
			allocated = new_alloc;

			//printf("Address of allocated %p\n", (void *) addresses[addr_index]);
			words_allocated++;
		}
		else if(!strcmp(command, "display") | !strcmp(command, "Display"))
		{
			displaymem();
		}
		else if(!strcmp(command, "free") | !strcmp(command, "Free"))
		{
			freemem();
		}
		else if(!strcmp(command, "invert") | !strcmp(command, "Invert"))
		{
			invert();
		}
<<<<<<< HEAD

=======
>>>>>>> e975773a74e5caf689b8f1cb72e20e59429e63b6
		else if(!strcmp(command, "exit") | !strcmp(command, "Exit"))
		{
			printf("Bye!\n");
			exit = true;
			return 0;
		}
		else if(!strcmp(command, "write") | !strcmp(command, "Write"))
		{
			write(allocated, words_allocated);
		}
		else
		{
			printf("\nFunction not yet implemented, try again later.\n");
		}
	}
}
