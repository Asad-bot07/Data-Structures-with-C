#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0'; // Return null if stack is empty
    }
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char expr[]) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]); // Push opening brackets
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char last = pop(); // Pop last opening bracket
            if (!isMatchingPair(last, expr[i])) {
                return 0; // Not a matching pair
            }
        }
    }
    return (top == -1); // Stack should be empty if balanced
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);
    //expr[strcspn(expr, "\n")] = '\0'; // Remove newline

    if (isBalanced(expr)) {
        printf("Balanced expression ✅\n");
    } else {
        printf("Unbalanced expression ❌\n");
    }

    return 0;
}
