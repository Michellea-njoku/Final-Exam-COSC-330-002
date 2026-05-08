#include "mylib.h"

double add(double a, double b) {
    return a + b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        return 0; // basic safety
    }
    return a / b;
}
