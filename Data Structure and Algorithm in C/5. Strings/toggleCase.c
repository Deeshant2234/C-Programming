#include <stdio.h>

/**
 * Program to toggle case of characters in a string
 * Converts uppercase to lowercase and vice versa
 */
int main()
{
    // Initialize string with size 12 (11 chars + null terminator)
    char str[12] = "How Are You";
    
    // Print original string
    printf("Original: \n");
    printf("%s",str);
    
    // Iterate through string until null terminator
    for(int i=0; str[i]!='\0'; i++)
    {   
        // If uppercase (ASCII 65-90), convert to lowercase
        if(str[i]>=65 && str[i]<=90)
            str[i]+=32;    // Add 32 to get lowercase ASCII value
            
        // If lowercase (ASCII 97-122), convert to uppercase
        else if(str[i]>=97 && str[i]<=122)
            str[i]-=32;    // Subtract 32 to get uppercase ASCII value
    }
    
    // Print modified string
    printf("\nToggleCase:\n");
    printf("%s",str);
    
    return 0;   // Program executed successfully
}