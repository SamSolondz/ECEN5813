#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "help.h"
#include "allocate.h"
#include "write.h"
#include "freemem.h"
#include "displaymem.h"
#include "invert.h"

void * addresses[10];	//pointer to allocated memory
int addr_index = 0;

int main(void)
{
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
			void * allocated = allocate();
			addresses[addr_index] = allocated;

			//printf("Address of allocated %p\n", (void *) addresses[addr_index]);
			addr_index++;
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
		else if(!strcmp(command, "exit") | !strcmp(command, "Exit"))
		{
			printf("Bye!\n");
			exit = true;
			return 0;
		}
		else if(!strcmp(command, "write") | !strcmp(command, "Write"))
		{
			write();
		}
		else
		{
			printf("\nFunction not yet implemented, try again later.\n");
		}
	}
}
