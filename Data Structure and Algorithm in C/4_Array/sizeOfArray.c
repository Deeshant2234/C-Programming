#include <stdio.h>

int main() {
   int arr[] = {1, 2, 3, 4, 5};
   size_t arr_size = sizeof(arr)/ sizeof(arr[0]);
   printf("The size of the array is %zu bytes\n", arr_size); 
   //%zu is a format specifier used in C
   //for printing the value of an object of type size_t.
   
   //PRINTING VAR ADDRESS
   printf("Address of arr_size %#X\n", &arr_size); 
   printf("Address of arr_size %X\n", &arr_size); 
   printf("Address of arr_size %x\n", &arr_size); 
   printf("Address of arr_size %#x\n", &arr_size); 

   // ACCESSING ARRAY ELEMENTS 
   printf("Access using  arr[2]: %d\n", arr[2]);         // Using direct indexing
   printf("Access using 2[arr]: %d\n", 2[arr]);          // Reversed indexing
   printf("Access using *(arr + 2): %d\n", *(arr + 2));  // Using pointer dereferencing
   return 0;
}
