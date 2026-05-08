#include <stdio.h>
#include "mylib.h"

int main() {
    int choice;
    double a, b, result;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add\n");
        printf("2. Multiply\n");
        printf("3. Divide\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter first number: ");
            scanf("%lf", &a);
            printf("Enter second number: ");
            scanf("%lf", &b);
        }

        switch (choice) {
            case 1:
                result = add(a, b);
                printf("Result: %.2f\n", result);
                break;

            case 2:
                result = multiply(a, b);
                printf("Result: %.2f\n", result);
                break;

            case 3:
                if (b == 0) {
                    printf("Can't divide by zero.\n");
                } else {
                    result = divide(a, b);
                    printf("Result: %.2f\n", result);
                }
                break;

            case 4:
                printf("Goodbye:)\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
