#include <stdio.h>
#define SIZE 100
void push(int stack[], int *top, int value) {
    if (*top >= SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++(*top)] = value;
    }
}
int pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[(*top)--];
    }
}
void reverseList(int arr[], int n) {
    int stack[SIZE];
    int top = -1;
    for (int i = 0; i < n; i++) {
        stack[top + 1] = arr[i];
        top++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = stack[top];
        top--;
    }
}

void display(int arr[], int n) {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[SIZE], n, choice;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display List\n");
        printf("2. Reverse List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                reverseList(arr, n);
                printf("List has been reversed.\n");
                display(arr, n);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
