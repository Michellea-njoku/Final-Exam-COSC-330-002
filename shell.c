#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

#define MAX_LINE 1024
#define MAX_ARGS 64

void print_help() {
    printf("Custom C Shell Commands:\n");
    printf("  reverse <text>       Reverse a string\n");
    printf("  multiply <a> <b>     Multiply two numbers\n");
    printf("  sqrt <number>        Find square root\n");
    printf("  help                 Show commands\n");
    printf("  exit                 Exit shell\n");
}

void parse_input(char *line, char **args) {
    int i = 0;
    char *token = strtok(line, " \t\n");

    while (token != NULL && i < MAX_ARGS - 1) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }

    args[i] = NULL;
}

int main() {
    char line[MAX_LINE];
    char *args[MAX_ARGS];

    printf("Welcome to Michelle's C Shell!\n");
    printf("Type 'help' to see available commands.\n");

    while (1) {
        printf("myshell> ");

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        parse_input(line, args);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        else if (strcmp(args[0], "help") == 0) {
            print_help();
        }
            
        else if (strcmp(args[0], "reverse") == 0) {
            if (args[1] == NULL) {
                printf("Usage: reverse <text>\n");
            } else {
                char text[100];
                strcpy(text, args[1]);

                reverseString(text);

                printf("%s\n", text);
            }
        }

        else if (strcmp(args[0], "multiply") == 0) {
            if (args[1] == NULL || args[2] == NULL) {
                printf("Usage: multiply <a> <b>\n");
            } else {
                double a = atof(args[1]);
                double b = atof(args[2]);

                printf("%.2f\n", multiply(a, b));
            }
        }
        
        else if (strcmp(args[0], "sqrt") == 0) {
            if (args[1] == NULL) {
                printf("Usage: sqrt <number>\n");
            } else {
                double num = atof(args[1]);
                double result = findSquareRoot(num);

                if (result == -1) {
                    printf("Cannot find square root of a negative number.\n");
                } else {
                    printf("%.2f\n", result);
                }
            }
        }

        else {
            printf("Unknown command: %s\n", args[0]);
            printf("Type 'help' to see available commands.\n");
        }
    }

    return 0;
}
