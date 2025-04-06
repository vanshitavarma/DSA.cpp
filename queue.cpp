#include<stdio.h> 
#define  MAX 10 
struct stack 
{ 
int arr [MAX ]; 
int top; 
}s; 

void push(); 
void pop(); 
void display(); 


void push() 
{ 
    int n; 
   if(s.top==MAX-1) 
    printf("STACK IS FULL!!"); 
   else 
    printf("ENTER  AN  ELEMENT: \n"); 
    scanf("%d",&n); 
    s.top++; 
    s.arr[s.top]=n; 
}

 
void pop() 
{ 
    int n; 
    if(s.top==-1) 
    printf("STACK  IS EMPTY!!\n"); 
    else 
    n=s.arr[s.top]; 
    s.top--; 
    printf("POPPED ELEMENT %d ",n); 
} 

 
void display() 
{ 
    int i; 
    if(s.top==-1) 
    printf("STACK IS EMPTY"); 
    else 
    printf("ELEMENTS OF STACK: \n"); 
    for(i=s.top; i>=0 ;i--) 
    printf("%d\n",s.arr[i]); 
} 
 
int main() 
{ 
    int choice; 
    s.top=-1; 
    do{ 
           printf("\n-----STACK------\n"); 
           printf("1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n"); 
           printf("ENTER  YOUR  CHOICE: "); 
           scanf("%d",&choice); 
 
           switch(choice) 
           { 
               case 1: 
               push(); 
               display(); 
               break; 
 
               case 2: 
               pop(); 
               display(); 
               break; 
 
               case 3: 
               display(); 
               break; 
 
               case 4: 
                    printf("EXITING THE PROGRAM"); 
                break; 
 
                default: 
                    printf("Invalid Input"); 
                break;
           } 
 
 
    }while(choice!=4); 
} 
 

