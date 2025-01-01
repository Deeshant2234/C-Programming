#include <stdio.h>

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    int binary[32];
    int index = 0;

    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimalNumber = 16; // Example decimal number

    printf("Decimal: %d\n", decimalNumber);
    decimalToBinary(decimalNumber);

    return 0;
}



