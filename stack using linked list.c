
#include<stdio.h>
#include <stdlib.h>

struct ll_node
{
	int data;
	struct ll_node *next;
	struct ll_node *top;
};

struct ll_node *push(struct ll_node *list,int value);
struct ll_node *pop(struct ll_node *list);
void display(struct ll_node *list);

void main()
{
	struct ll_node *list;
	int choice,val;
	list=NULL;
	while (1)
	{
		printf("1.Push\n2.Pop\n3.Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the value to be pushed: ");
			scanf("%d",& val);
			list=push(list,val);
			display(list);
			break;

		case 2:
			list=pop(list);
			display(list);
			break;

		case 3:
		printf("Exiting");
			exit(0);

		default:
			printf("Invalid choice!\n");
		}
	}
}

struct ll_node *push(struct ll_node *top,int value)
{
	struct ll_node *pnew;
	pnew=(struct ll_node*)malloc(sizeof(struct ll_node));
	pnew->data=value;
	pnew->next=NULL;
	if(top==NULL)
	{
		top=pnew;
		return pnew;
	}
	pnew->next=top;
	top=pnew;
	return pnew;
}

struct ll_node *pop(struct ll_node *top)
{
	struct ll_node *n2d;
	if (top==NULL)
	{
	    printf("Stack is empty\n");
        return top;
	}
	n2d=top;
	top=top->next;
	free(n2d);
	return top;
}

void display(struct ll_node *top)
{
    if(top==NULL)
    {
        printf("Stack is empty");
        printf("\n");
        return;
    }
    struct ll_node *hp;
    printf("Stack elements:\n");
    hp=top;
    while (hp!=NULL)
    {
        printf("%d\n",hp->data);
        hp=hp->next;
    }
    printf("\n");
}
