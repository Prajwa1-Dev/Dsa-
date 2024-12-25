#include <stdio.h>
#include <string.h>
#define MAX 5

int stack[MAX], top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push() {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    int element;
    printf("Enter element to push: ");
    scanf("%d", &element);
    stack[++top] = element;
    printf("%d pushed onto the stack.\n", element);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from the stack.\n", stack[top--]);
}

void checkPalindrome() {
    if (isEmpty()) {
        printf("Stack is empty, cannot check palindrome.\n");
        return;
    }
    int i, isPalin = 1;
    for (i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            isPalin = 0;
            break;
        }
    }
    if (isPalin)
        printf("The stack contents form a palindrome.\n");
    else
        printf("The stack contents do not form a palindrome.\n");
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Check Palindrome\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: checkPalindrome(); break;
        case 4: display(); break;
        case 5: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}