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
#include "pattern.h"
#include "readin.h"
#include "frdm.h"


//#define FRDM	1 //uncommment this to run on the FRDM-KL25Z eval board

#ifdef FRDM
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#define printf PRINTF
#endif

//The terminal function keeps track of what has been allocated using a pointer to the start of allocated memoru.
//Memory edits are done in functions.
int words_allocated = 0;
int word_size = sizeof(unsigned long);

int main(void)
{
  #ifdef FRDM
  /* Init board hardware. */
  BOARD_InitPins();
  BOARD_BootClockRUN();
  BOARD_InitDebugConsole();
  #endif

  void * allocated = 0;
	bool exit = false;
	while(exit == false)

	{
		printf("\n\r------------------------------------------------------------------");
		printf("\n\rEnter a command. Type 'Help' to get a list of commands. Type 'Exit' to quit.\n\r");

		char command[12];

		#ifdef FRDM
			readin(command, sizeof(command));
		#else
			scanf("%25s", command);
		#endif

		if(!strcmp(command, "help") | !strcmp(command, "Help"))
		{
			help();
		}
		else if(!strcmp(command, "allocate") | !strcmp(command, "Allocate"))
		{
			allocated = allocate(allocated);
		}
		else if(!strcmp(command, "free") | !strcmp(command, "Free"))
		{
			allocated = freemem(allocated);
		}
		else if(!strcmp(command, "display") | !strcmp(command, "Display"))
		{
			displaymem(allocated);
		}
		else if(!strcmp(command, "invert") | !strcmp(command, "Invert"))
		{
			invert(allocated);
		}
		else if(!strcmp(command, "exit") | !strcmp(command, "Exit"))
		{
			printf("\n\rBye!");
			exit = true;
			return 0;
		}
		else if(!strcmp(command, "write") | !strcmp(command, "Write"))
		{
			write(allocated, words_allocated);
		}
		else if(!strcmp(command, "pattern") | !strcmp(command, "Pattern"))
		{
			pattern(allocated, 0);
		}
		else if(!strcmp(command, "verify") | !strcmp(command, "Verify"))
		{
			pattern(allocated, 1);
		}

		else
		{
			printf("\n\rFunction not yet implemented, try again later.\n");
		}
	}
}
