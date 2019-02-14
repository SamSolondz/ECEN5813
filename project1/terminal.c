#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "help.h"
int main(void)
{
	bool exit = false;
	char command[20];
	printf("------------------------------------------------------------------\n");
	printf("Enter a command. Type 'Help' to get a list of commands\n");
	
	while(exit == false)
	{
	        printf("Input: ");
	        scanf("%20s", command);

		if(!strcmp(command, "help") | !strcmp(command, "Help"))
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
			printf("Command not recognized, try again\n");
	}
}
