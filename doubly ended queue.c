#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = front;
    newNode->prev = NULL;
    if (front != NULL) front->prev = newNode;
    front = newNode;
    if (rear == NULL) rear = newNode;
}

void insertRear(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;
    if (rear != NULL) rear->next = newNode;
    rear = newNode;
    if (front == NULL) front = newNode;
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if (front != NULL) front->prev = NULL;
    else rear = NULL;
    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = rear;
    rear = rear->prev;
    if (rear != NULL) rear->next = NULL;
    else front = NULL;
    free(temp);
}

void displayDeque() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    do {
        printf("\nMenu:\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}
