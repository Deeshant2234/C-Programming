#include <stdio.h>

int main() {
   printf("The size of a pointer is %d bytes\n", sizeof(void *));
   return 0;
}

//Note that the void * type is used here to represent a generic pointer, 
//as the size of a pointer may vary depending on the specific data type being pointed to.