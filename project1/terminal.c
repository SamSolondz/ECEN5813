#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "help.h"
#include "allocate.h"
#include "write.h"


int main(void)
{
	bool exit = false;
	printf("------------------------------------------------------------------\n");
	printf("Enter a command. Type 'Help' to get a list of commands. Type 'Exit' to quit.\n");


	 void * addresses[10];	//pointer to allocated memory
	 int i = 0;
	while(exit == false)
	{
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
			addresses[i] = allocated;

			printf("Address of first block is %p\n", (void *) addresses[i]);
			i++;
		}
		else if(!strcmp(command, "free") | !strcmp(command, "Free"))
		{
			//free();
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
