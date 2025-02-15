#include <stdio.h>

// Function prototypes for the operations
float add(int a, int b);
float subtract(int a, int b);
float multiply(int a, int b);
float divide(int a, int b);

int main() {
    int num1, num2, choice;
    float result;

    // Array of function pointers
    float (*fPtr[])(int, int) = {add, subtract, multiply, divide};

    // Taking input from the user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Displaying the menu
    printf("Select an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Performing the selected operation using function pointers
    if (choice >= 1 && choice <= 4) 
    {
        if (choice == 4 && num2 == 0) 
            printf("Error: Division by zero is not allowed.\n");
        else
        {
            result = fPtr[choice - 1](num1, num2);
            printf("Result: %.2f\n", result);
        }
    } 
    else 
        printf("Invalid choice.\n");

    return 0;
}

// Function definitions
float add(int a, int b)
{
    return a + b;
}

float subtract(int a, int b)
{
    return a - b;
}

float multiply(int a, int b)
{ 
    return a * b;
}

float divide(int a, int b)
{
    return (float)a / b;
}