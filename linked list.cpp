#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node*add;
	
};
void create();
void display();

struct node*start=NULL,*new1,*prev,*next,*temp;

int main()
{
	int choice;
	while(choice!=6)
	{
	printf("\n-----Linked List-------\n");
	printf("1.Create\n2.Insert on first\n3.Insert on Last\n4.Insert on Middle\n5.Display\n6.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	
	switch(choice)
    { 
    case 1:
        create();
    	display();
    	break;
    case 2:
    	printf("insert element on first");
        break;
    case 3:
    	printf("insert element on last");
    	break;
    case 4:
    	printf("insert element in middle");
    	break;
    case 5:
    	display();
    	break;
    case 6:
    	printf("exiting");
    	break;
    default:
    	printf("invalid input");

    } 
	
}
}

void create()
{
	char ch;
	int n;
	printf("Enter an element: ");
	scanf("%d",&n);
	start=(struct node*)(malloc(sizeof(struct node)));
	start->data=n;
	start->add=NULL;
	temp=start;
	printf("want to continue (y/n)");
	ch=getche();
	while(ch=='y'||ch=='Y')
	{
		printf("\nenter next element");
		scanf("%d",&n);
		new1=(struct node*)(malloc(sizeof(struct node)));
		new1->data=n;
		new1->add=NULL;
		temp->add=new1;
		temp=temp->add;
		printf("want to continue?? (y/n)");
		ch=getche();
				
	}
}
void display()
{
	if(start==NULL)
	printf("list not found");
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->add;
		}
	}
	
}
