#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL; // Global variable for the stack top

// Function to push an element onto the stack
void push() {
    int x;
    struct node* t = (struct node*)malloc(sizeof(struct node)); // Memory allocation
    if (t == NULL) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter the value you want to insert: ");
        scanf("%d", &x);
        t->data = x;  // Set the value in the new node
        t->next = top; // Link the new node to the top of the stack
        top = t;       // Update the top to the new node
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n"); // Stack is empty
    } else {
        struct node* temp = top;
        top = top->next; // Move the top pointer to the next node
        free(temp);      // Free the old top node
        printf("Element popped\n");
    }
}

// Function to display the elements of the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n"); // If the stack is empty
    } else {
        struct node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data); // Print each element
            temp = temp->next;         // Move to the next node
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("----MENU-----\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(); // Take the value inside the push function
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program!!!\n");
                break;
            default:
                printf("Invalid Input\n");
        }
    } while (choice != 4);
    return 0;
}

