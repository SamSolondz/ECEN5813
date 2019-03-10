/*
 * readin.c
 *
 *  Created on: Mar 10, 2019
 *      Author: sam
 */
#include "readin.h"
void readin(char * command, int length)
{
	char temp[length];
	char ch = 'a';
	int i = 0;
	while(ch != 13)
	{
	  ch = GETCHAR();
	  switch(ch)
	  {
	  case 127:
		  PUTCHAR(ch);
		  temp[i] = 0;
		  if(i > 0)
			  i--;
		  break;
	  case 13:
		  break;
	  default:
		  if(i < length) //input is not a char ....&& (ch > 64 && ch < 123)
		  {
			  PUTCHAR(ch);
			  temp[i] = ch;
			  i++;
		  }
		  break;
	  }
  }
	temp[i] = 0;
	strcpy(command, temp);
}
