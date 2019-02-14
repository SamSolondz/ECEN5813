#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "help.h"
int main(void)
{
	bool exit = false;
	printf("------------------------------------------------------------------\n");
	printf("Enter a command. Type 'Help' to get a list of commands\n");
	while(exit == false)
	{
	        char command[16];
		printf("Input: ");
	        scanf("%15s", command); 	//TODO: protect against a user input that is too long.
		if(sizeof(command) > 20)
		{
			printf("\nCommand not recognized, try again\n");
		}
		else if(!strcmp(command, "help") | !strcmp(command, "Help"))
		{
			help();
		}
		else if(!strcmp(command, "exit") | !strcmp(command, "Exit"))
		{
			printf("Goodbye\n");
			exit = true;
			return 0;
		}
		else
		{
			printf("\nCommand not recognized, try again\n");
		}
	}
}
