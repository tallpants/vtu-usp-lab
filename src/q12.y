%{ #include <ctype.h>
  char str[20];
  int i = 0;
%}

%token id
%left '+''/''*''-'

%%
E:S { infix_postfix(str); }
S:S'+'T|S'-'T|T;
T:T'*'F|T'/'F|F;
F:id|'('S')';
%%

#include <stdio.h>

main() {
  printf("Enter an expression: ");
  yyparse();
}

yyerror() {
  printf("\nInvalid.\n");
}

yylex() {
  char ch;
  while (ch != '\n') {
    ch = getchar();
    str[i++] = ch;
    if (isalpha(ch)) return id;
    if (ch == '+' || ch == '*' || ch == '-' || ch == '/') return ch;
  }
  str[--i] = '\0';
  return 0;
}

void push(char stack[], int *top, char ch) {
  stack[++(*top)] = ch;
}

char pop(char stack[], int *top) {
  return (stack[(*top)--]);
}

int prec(char ch) {
  switch (ch) {
    case '/':
    case '*': return 2;
    case '+':
    case '-': return 1;
    case '(': return 0;
    default: return -1;
  }
}

void infix_postfix(char infix[]) {
  int top = -1, iptr = -1, pptr = -1;
  char postfix[20], stack[20], ss, cs;
  push(stack, &top, '\0');
  while ((cs = infix[++iptr]) != '\0') {
    switch (cs) {
      case '(': push(stack, &top, cs);
                break;
      case ')': ss = pop(stack, &top);
                while (ss != '(') {
                  postfix[++pptr] = ss;
                  ss = pop(stack, &top);
                }
                break;
      case '*':
      case '/':
      case '+':
      case '-': while (prec(stack[top]) >= prec(cs))
                  postfix[++pptr] = pop(stack, &top);
                push(stack, &top, cs);
                break;
      default: if (isalnum(cs) == 0) {
                 printf("\nError.\n");
                 exit(1);
               }

               postfix[++pptr] = cs;
    }
  }

  while (top != -1) {
    postfix[++pptr] = pop(stack, &top);
  }

  printf("%s\n", postfix);
}