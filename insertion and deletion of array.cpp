#include<stdio.h> 

int a[20], size; 

void insert(int position, int ele); 
void deleteElement(); 
void display(); 

void insert(int position, int ele) 
{ 
    if (position <= 0 || position > size + 1) 
    { 
        printf("Invalid Position\n"); 
        return; 
    } 
    if (size >= 20) 
    { 
        printf("Array Is Full\n"); 
        return; 
    } 
    for (int i = size - 1; i >= position - 1; i--) 
    { 
        a[i + 1] = a[i]; 
    } 
    a[position - 1] = ele; 
    size++; 
} 

void deleteElement() 
{ 
    int position; 
    printf("Enter the position of the element to be deleted: "); 
    scanf("%d", &position); 
    
    if (position <= 0 || position > size) 
    { 
        printf("Invalid position\n"); 
        return; 
    } 

    int x = a[position - 1]; 
    for (int i = position - 1; i < size - 1; i++) 
    { 
        a[i] = a[i + 1]; 
    } 
    size--; 
    printf("The deleted element is: %d\n", x); 
} 

void display() 
{ 
    if (size == 0) 
    { 
        printf("\nArray is empty\n"); 
        return; 
    } 

    printf("Elements in array are: \n"); 
    for (int i = 0; i < size; i++) 
        printf("%d\n", a[i]); 
} 

int main() 
{ 
    int choice; 
    printf("Enter size of array: "); 
    scanf("%d", &size); 

    if (size > 20) 
    { 
        printf("\nOverflow\n"); 
        return 0; 
    } 

    printf("Enter elements of array:\n"); 
    for (int i = 0; i < size; i++) 
    { 
        scanf("%d", &a[i]); 
    } 

    do 
    { 
        printf("------MENU------\n"); 
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        
        switch (choice) 
        { 
            case 1: 
            { 
                int position, ele; 
                printf("Enter The Position Of Element to be Inserted: "); 
                scanf("%d", &position); 
                printf("Enter The Element You Want To Insert: "); 
                scanf("%d", &ele); 
                insert(position, ele); 
                display(); 
                break; 
            } 

            case 2: 
                deleteElement(); 
                display(); 
                break; 

            case 3: 
                display(); 
                break; 

            case 4: 
                printf("EXITING THE PROGRAM!!!!\n"); 
                break; 

            default: 
                printf("Invalid Input\n"); 
        } 
    } while (choice != 4); 

    return 0; 
} 
 
 
 

