#include <stdio.h>

int main()
{
    char str[12] = "How are you";
    printf("------------------------------------------------------\n");
    printf("Printing as single-2 char using %%c format Specifier :-\n");
    for(int i=0;str[i]!='\0';i++)
    {   
        printf("%c",str[i]);
    }
    printf("\n------------------------------------------------------");
    printf("\nPrinting using %%s format specifier :-\n");
    printf("%s",str);   
    return 0;
}

/* %s format specifier print complete char array till null terminator */