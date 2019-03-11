#include <stdlib.h>
#include <stdio.h>

// taken from deep c secrets to test maximum amount we can allocate

void max(){
	int Mb = 0;
	while (malloc(1<<20))
	{
		 ++Mb;
		printf("Allocated %d Mb total\n", Mb);
	}
}
