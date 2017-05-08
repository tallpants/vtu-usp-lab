/*
 * Write a C program to implement the syntax-directed definition
 * of "if E then S1" and "if E then S1 else S2".
 */

/*
 * $ ./a.out
 * Examples:
 * if (a<b) then (s=a)
 * if (a<b) then (s=a) else (s=b)
 *
 * Enter a statement: if (a<b) then (s=a)
 *
 * Syntax Driven Definition:
 * --------------------------
 *
 * if (a<b)
 *   goto 101
 *
 * 101: (s=a)
 * 102: ...
 *
 * $ ./a.out
 * Examples:
 * if (a<b) then (s=a)
 * if (a<b) then (s=a) else (s=b)
 *
 * Enter a statement: if (a<b) then (s=a) else (s=b)
 *
 * Syntax Driven Definition:
 * --------------------------
 *
 * if (a<b)
 *   goto 101
 * goto 102
 *
 * 101: (s=a)
 * 102: (s=b)
 * 103: ...
 */

/*
 * strtok - extract tokens from strings
 * =====================================
 *
 * #include <string.h>
 *
 * char *strtok(char *str, const char *delim);
 *
 * This function breaks a string into a sequence of tokens. On the first
 * call the string to be parsed should be specified in str. In each
 * subsequent call that should parse the same string, str must be NULL.
 *
 * Each call to strtok() returns a pointer to a string containing the next
 * token (excluding the delimiter). If no more tokens are found, NULL
 * is returned.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token_list {
    int length;
    char* tokens[100];
} list;

/**
 * Divides the string into tokens using spaces as the delimiter, and
 * stores the tokens in the struct list.
 */
void tokenize(char* string);

/**
 * Prints the syntax directed definition.
 * If S2 does not exist (i.e there is no else part), then it should be
 * passed as NULL.
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
    printf("goto 102\n");

    printf("\n101: %s", S1);

    if (S2) {
        printf("\n     goto 103");
        printf("\n102: %s", S2);
        printf("103: ...\n");
    } else {
        printf("102: ...\n");
    }
}
