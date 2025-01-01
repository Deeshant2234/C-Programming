#include <stdio.h>

void convolution(int x[], int h[], int y[], int x_len, int h_len) {
    int y_len = x_len + h_len - 1;
    for (int i = 0; i < y_len; i++) {
        y[i] = 0;
        for (int j = 0; j < h_len; j++) {
            if (i - j >= 0 && i - j < x_len) {
                y[i] += x[i - j] * h[j];
            }
        }
    }
}

int main() {
    int x[5] = {1, 2, 3, 4, 5}; // Example signal 1
    int h[3] = {1, 1, 1};       // Example signal 2
    int y[7];                   // Resultant signal length will be 5 + 3 - 1 = 7

    convolution(x, h, y, 5, 3);

    printf("Convolution result:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    return 0;
}