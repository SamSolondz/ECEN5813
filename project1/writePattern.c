#include <time.h>

void writePattern()
{ 
    unsigned long seed = 0;
    unsigned long * address = 0;
    unsigned long num = 0;
    unsigned long max = 0;
    unsigned long min = 0;
    float pattern[num];
    clock_t timer;

    printf("(Write Pattern)\n\n");

    // get address, seed, and number in pattern
    timer = clock();
    printf("What's the address where you would like to store the pattern?\n");
    scanf("%p", &address);
    printf("Enter a seed value to generate the pattern.\n");
    scanf("%li", &seed);
    printf("How many numbers would you like generated?\n");
    scanf("%li", &num);
    printf("Specify the pattern range:\n");
    printf("Enter the maximum number.\n");
    scanf("%li", &max);
    printf("Enter the minimum number.\n");
    scanf("%li", &min);
    
    // print pattern start
    printf("Requested pattern:");
    
    // determine random numbers and print pattern numbers within specified range
    for (int i=0; i<num; i++)
    {
        pattern[i]= ((2*seed + 0) % 9) % ((max - min + 1) + min);
        printf("%f, ", pattern[i]);
    }

    timer = clock() - timer;
    double functionTiming = ((double)timer)/CLOCKS_PER_SEC;
    printf("\npatternWrite took %lf seconds to complete.\n", functionTiming);
    
    free(*ptr);

    return;
}
