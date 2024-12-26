#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % MAX == front;
}

void insert() {
    char element;
    if (isFull()) {
        printf("Queue Overflow! Cannot insert more elements.\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf(" %c", &element);
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = element;
    printf("Inserted '%c' into the queue.\n", element);
}

void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    printf("Deleted '%c' from the queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    int i = front;
    do {
        printf("%c ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}