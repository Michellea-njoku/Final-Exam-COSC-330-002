#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mylib.h"

void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

double multiply(double a, double b) {
    return a * b;
}

double findSquareRoot(double num) {
    if (num < 0) {
        return -1;
    }
    return sqrt(num);
}
