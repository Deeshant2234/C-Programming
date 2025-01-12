#include <stdio.h>

int main()
{   
    char str[] = "   How   are you  ";
    int i = 0;
    int count = 0;  // Start with 0
    
    // Skip leading spaces
    while(str[i] == ' ') i++;
    
    // If not empty string, count first word
    if(str[i] != '\0') count = 1;
    
    // Count remaining words
    while(str[i] != '\0')
    {
        if(str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0')
            count++;
        i++;
    }
    
    printf("Word Count: %d\n", count);
    return 0;
}
