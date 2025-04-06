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
    if((s.rear+1)%MAX==s.front)
        printf("ARRAY IS FULL!!!\n");
    else
     {
        printf("Enter an element:  ");
        scanf("%d",&n);
        if(s.rear==-1&&s.front==-1)
	    { 
	        s.front=0;
	        s.rear=0;
		}
		else
		{
			s.rear=(s.rear+1)%MAX;
		}
        s.arr[s.rear]=n;
    }
}

void dequeue()
{
    int n;
    if(s.front==-1 && s.rear==-1)
        printf("ARRAY IS EMPTY!!!\n");
    else
    {
        n=s.arr[s.front];
        if(s.front==s.rear)
        {
        	s.front=-1;
        	s.rear=-1;
		}
		else
		{
			s.front=(s.front+1)%MAX;
			printf("deleted element is %d ");
		}
        
    }
}

void display()
{
    int i;
    if (s.front == -1 && s.rear == -1) 
	{
        printf("ARRAY IS EMPTY!!!\n");
    } 
    else
	{
        printf("Queue Elements: \n");
        i = s.front;
        do 
		{
            printf(" %d", s.arr[i]);
            i = (i + 1) % MAX;
        } while (i != (s.rear + 1) % MAX);   
        printf("\n");
    }	
}

int main()
{
     int choice;
      s.rear=-1;
      s.front=-1;
     do{
           printf("-------CIRCULAR QUEUE MENU------\n");
           printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
