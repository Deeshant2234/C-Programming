// Seed the random number generator with the current time
// This ensures that the random numbers generated are different each time the program runs
// NULL is used in time(NULL) to get the current calendar time

// Generate a random number between 0 and i (inclusive)
// rand() generates numbers from 0 to RAND_MAX
// % operator gives remainder from 0 to (operand-1)
// For range 0 to i (inclusive), we need i+1 numbers

// Reference Youtube Video: https://youtu.be/tLxBwSL3lPQ?si=8EOSXo9HssGto560

#include <stdio.h>
#include <stdlib.h> // srand() and rand()
#include <time.h>

void swap(char* a, char* b)
{
    if(a!=b)
    {
        *a = *a^*b;
        *b = *a^*b;
        *a = *a^*b;
    }
}

void fisherYatesShuffleAlgo(char *a, int i)
{                           
    int random_number, temp;

    /* Seeds the random number generator - We used current time here as a seed */
    srand(time(NULL));

    while(--i>0)
    {
        /* rand() uses the seed to generate random number */
        random_number = rand() % (i + 1);  
        swap(&a[random_number],&a[i]);
    }
}

int main()
{
    char arr[] = "ABCDEFGH";
    int length = sizeof(arr)/sizeof(arr[0])-1; 
    
    fisherYatesShuffleAlgo(arr,length);

    /* Printing Character Array After Shuffling */
    printf("%s",arr);
    
    return 0;
}