#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) 
{ stack[++top] = c;}
char pop()
 { return stack[top--]; }
char peek() 
{ return (top == -1) ? -1 : stack[top]; }
int precedence(char c) 
{ return (c == '^') ? 3 : (c == '*' || c == '/' || c == '%') ? 2 : (c == '+' || c == '-') ? 1 : 0; }

void infixToPostfix(char* in, char* post) {
    int i = 0, j = 0;
    char c;
    while ((c = in[i++]) != '\0') {
        if (isalnum(c)) {
            post[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(') {
                post[j++] = pop();
            }
            pop(); // Remove '('
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                post[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        post[j++] = pop();
    }
    post[j] = '\0'; // Null-terminate the string
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression:\n");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline, if any
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
