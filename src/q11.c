/*
 * Write a C program to implement the syntax-directed definition
 * of "if E then S1" and "if E then S1 else S2".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token_list {
    int length;
    char* tokens[100];
} list;

/**
 * [tokenize description]
 * @param string [description]
 */
void tokenize(char* string);

/**
 * [print_sdd description]
 * @param E  [description]
 * @param S1 [description]
 * @param S2 [description]
 */
void print_sdd(char* E, char* S1, char* S2);

int main(void) {

    char statement[100];

    printf("Examples: \n");
    printf("if (a<b) then (s=a)\n");
    printf("if (a<b) then (s=a) else (s=b)\n");

    printf("Enter a statement: ");
    fgets(statement, 100, stdin);

    tokenize(statement);

    if (list.length != 4 && list.length != 6) {
        printf("Invalid syntax.\n");
        exit(1);
    }

    char *E, *S1, *S2;

    E = list.tokens[1];
    S1 = list.tokens[3];

    if (list.length == 6)
        S2 = list.tokens[5];

    printf("\nSyntax Directed Definition:\n");
    printf("----------------------------\n");
    print_sdd(E, S1, S2);

    return 0;
}

void tokenize(char* string) {

    list.length = 0;

    char* token = strtok(string, " ");

    for (int i = 0; token != NULL; i++) {
        list.tokens[i] = token;
        list.length += 1;
        token = strtok(NULL, " ");
    }
}

void print_sdd(char* E, char* S1, char* S2) {

    printf("\nif %s\n", E);
    printf("  goto 101\n");
    if (S2) printf("goto 102\n");

    printf("\n101: %s", S1);

    if (S2) {
        printf("\n102: %s", S2);
        printf("103: ...\n");
    } else {
        printf("102: ...\n");
    }
}
