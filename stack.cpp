#include<stdio.h>
#define MAX 10
struct queue
{
    int arr[MAX];
    int rear;
    int front;
}s;

void enqueue();
void dequeue();
void display();

void enqueue()
{
    int n;
    if(s.rear==MAX-1)
        printf("ARRAY IS FULL!!!\n");
    else
    {
        printf("Enter an element:  ");
        scanf("%d",&n);
        s.rear++;
        s.arr[s.rear]=n;
    }
}

void dequeue()
{
    int n;
    if(s.front>s.rear)
        printf("ARRAY IS EMPTY!!!\n");
    else
    {
        n=s.arr[s.front];
        printf("%d\n",n);
        s.front++;
    }
}

void display()
{
    int i;
    if(s.front>s.rear)
        printf("ARRAY IS EMPTY!!!\n");
    else
    {
        printf("Queue Elements: \n");
        for(i=s.rear;i>=s.front;i--)
        {
            printf("%d\n",s.arr[i]);
        }
    }
}

int main()
{
     int choice;
      s.rear=-1;
      s.front=0;
     do{
           printf("-------MENU------\n");
           printf("1.Enqueue\n 2.Dequeue\n  3.Display\n 4.Exit\n ");
           printf("Enter your choice: ");
           scanf("%d",&choice);

           switch(choice)
           {
           case 1:
                       enqueue();
                       display();
                       break;

           case 2:
                      dequeue();
                      display();
                      break;

           case 3:
                      display();
                      break;

           case 4:
                      printf("EXIT!!!!");
                      break;

           default:
                     printf("Invalid Input");


           }



     }while(choice!=4);
}
