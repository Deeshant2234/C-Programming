// Include necessary header files
#include <stdio.h>
#include <string.h>

int main() {

    // Declare variables to store the input string and the reversed string
    char str[10], rev[10];
    int len, i, j;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    // gets(str);                       // Note: gets() is unsafe, consider using fgets() instead
    // scanf("%s", str)                 // stops reading at whitespace, unsafe -> cause overflow 
    fgets(str, sizeof(str), stdin); 

    // Calculate the length of the input string
    len = strlen(str);

    for (i = 0, j = len - 1; j >= 0; i++, j--) {
        rev[i] = str[j];
    }
    rev[i] = '\0'; // Null-terminate for reversed string

    // If null-terminator is not added, then printf will 
    // keep printing characters until it finds a null-terminator
    
    printf("Reversed string: %s\n", rev);

    return 0; // Indicate that the program ended successfully
}
