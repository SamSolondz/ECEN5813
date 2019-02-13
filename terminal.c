#include <stdio.h>

int main(void)
{

	printf("-----------------------------------------------------\n");
	printf("Welcome. Please select an option below:\n");
	printf("\t1. Option 1\n");
	printf("\t2. Option 2\n");
	printf("\t3. Exit\n");
	printf("---Number select: ");
	
	int input;
	scanf("%d", &input);
	if(input == 3)
	{
		printf("\nGoodbye!");
		return 0;
	}
}
