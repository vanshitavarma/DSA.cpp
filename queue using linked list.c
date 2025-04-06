#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue() {
    int ele;
    printf("Enter the element to enqueue: ");
    scanf("%d", &ele);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("%d enqueued\n", ele);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }

    struct node *temp = front;
    printf("%d dequeued\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;  // Reset rear if the queue is empty
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *curr = front;
    printf("Queue elements: ");
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n"); // Fixed syntax error: added missing semicolon
}

int main() {
    int choice;

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
