/* Union is a special data type in C that allows to store different
data types in the same memory location - To efficient memory management.
Unlike structures, where each member has its own storage location, 
members of a union share the same memory location. This means that 
only one member can contain a value at any given time. The size of 
the union is determined by the size of its largest member. */

#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

struct DataStruct {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    struct DataStruct dataStruct;

    // Demonstrating union
    data.i = 10;
    printf("Union - data.i : %d\n", data.i);

    data.f = 220.5;
    printf("Union - data.f : %f\n", data.f);

    strcpy(data.str, "C Programming");
    printf("Union - data.str : %s\n", data.str);

    // Note: After assigning a new value to one member, the previous
    // values are lost
    printf("Union - data.i after setting data.str: %d\n", data.i);
    printf("Union - data.f after setting data.str: %f\n", data.f);

    printf("Size of Union : %lu\n", sizeof(data));

    // Demonstrating struct
    dataStruct.i = 10;
    dataStruct.f = 220.5;
    strcpy(dataStruct.str, "C Programming");

    printf("Struct - dataStruct.i : %d\n", dataStruct.i);
    printf("Struct - dataStruct.f : %f\n", dataStruct.f);
    printf("Struct - dataStruct.str : %s\n", dataStruct.str);

    printf("Size of Struct : %lu\n", sizeof(dataStruct));

    return 0;
}