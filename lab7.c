#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char usn[20], name[30], prog[30];
    int sem;
    long phNo;
    struct Node *link;
};

typedef struct Node *NODE;
NODE head = NULL;
int count = 0;

NODE createNode() {
    NODE temp = (NODE)malloc(sizeof(struct Node));
    printf("Enter USN, Name, Programme, Sem, Phone: ");
    scanf("%s %s %s %d %ld", temp->usn, temp->name, temp->prog, &temp->sem, &temp->phNo);
    temp->link = NULL;
    count++;
    return temp;
}

void insertFront() {
    NODE temp = createNode();
    temp->link = head;
    head = temp;
}

void insertEnd() {
    NODE temp = createNode();
    if (!head) {
        head = temp;
        return;
    }
    NODE cur = head;
    while (cur->link) cur = cur->link;
    cur->link = temp;
}

void deleteFront() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = head;
    head = head->link;
    printf("Deleted: %s\n", temp->usn);
    free(temp);
    count--;
}

void deleteEnd() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    if (!head->link) {
        printf("Deleted: %s\n", head->usn);
        free(head);
        head = NULL;
    } else {
        NODE cur = head, prev = NULL;
        while (cur->link) {
            prev = cur;
            cur = cur->link;
        }
        printf("Deleted: %s\n", cur->usn);
        free(cur);
        prev->link = NULL;
    }
    count--;
}

void display() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    NODE cur = head;
    printf("SLL Contents:\n");
    while (cur) {
        printf("USN: %s, Name: %s, Programme: %s, Sem: %d, PhNo: %ld\n",
               cur->usn, cur->name, cur->prog, cur->sem, cur->phNo);
        cur = cur->link;
    }
    printf("Total nodes: %d\n", count);
}

int main() {
    int choice;
    do {
        printf("\n1. Insert at Front\n2. Insert at End\n3. Delete from Front\n4. Delete from End\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: insertFront(); break;
        case 2: insertEnd(); break;
        case 3: deleteFront(); break;
        case 4: deleteEnd(); break;
        case 5: display(); break;
        case 6: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}