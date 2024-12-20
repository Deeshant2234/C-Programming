#include <stdio.h>

int main() {
   int arr[] = {1, 2, 3, 4, 5};
   size_t arr_size = sizeof(arr) / sizeof(arr[0]);
   printf("The size of the array is %zu bytes\n", arr_size); 
   //%zu is a format specifier used in C
   //for printing the value of an object of type size_t.
   return 0;
}
