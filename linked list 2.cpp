#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
	
};
struct node*insert(struct node*list,int value);
struct node*del(struct node*list,int target);

void display(struct node*list);
int main()
{
	struct node*mylist;
	int choice,value;
	mylist=NULL;
	while(choice!=4)
	{
		printf("---MENU----");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("enter value to be inserted");
				scanf("%d",&value);
				mylist=insert(mylist,value);
				break;
				
				case 2:
					printf("\nEnter value to be deleted");
					scanf("%d",&value);
					mylist=del(mylist,value);
					break;
					
					case 3:
						display(mylist);
						break;
					case 4:
						printf("Exiting program...");
						break;
					default:
						printf("Invalid choice!\n");
						
		}
	}
}

struct node*insert(struct node*list,int value)
{
	struct node*pnew,*hp;
	pnew=(struct node*)malloc(sizeof(struct node));
	pnew->data=value;
	pnew->next=NULL;
	
	if(list==NULL||list->data>value)
	{
		pnew->next=list;
		list=pnew;
		return list;
	}
	hp=list;
	while(hp->next!=NULL && hp->next->data<value)
	
	hp=hp->next;
	pnew->next=hp->next;
	hp->next=pnew;
	return list;
} 
	

void display(struct node*list)
{
	struct node*hp;
	hp=list;
	printf("\n");
	while(hp!=NULL)
	{
		printf("%d",hp->data);
		hp=hp->next;
	}
	
	return;
}

struct node *del(struct node *list,int target)
{
    struct node *help_ptr, *node2delete;
	help_ptr = list;
	if (help_ptr != NULL) 
	{
		if (help_ptr->data == target) 
		{
			list = help_ptr->next;
			free(help_ptr);
			return list;
		}
		while (help_ptr->next != NULL) 
		{
			if (help_ptr->next->data == target) 
			{
				node2delete = help_ptr->next;
				help_ptr->next = help_ptr->next->next;
				free(node2delete);   
				return list;
			}
			help_ptr = help_ptr->next;
		}
            printf("Element not found");
		return list;
	}
	printf("List empty");
	return list;
 
}

