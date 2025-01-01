#include <stdbool.h>
#include <stdio.h>

int main() {
    bool value = true;
    printf("Boolean value: %s\n", value ? "true" : "false");
    return 0;
}

/*
-- There is no specific format specifier for bool in C.
-- Use %d to print 1 or 0 for true and false.
-- Use conditional expressions or helper functions to
print "true" or "false". 
*/