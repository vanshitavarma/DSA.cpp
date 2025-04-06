#include<stdio.h>

#include<stdlib.h>

struct node

{

	int data;

	struct node *right;

	struct node *left;

};

struct node *root=NULL;

struct node *insert(struct node *root,int n)

{

	struct node *temp=root;

	struct node *new=(struct node *)malloc(sizeof(struct node));

	new->data=n;

	new->right=NULL;

	new->left=NULL;

	if(root==NULL)

	{

		root=new;

		return root;

	}

	if(new->data < temp->data)

		temp->left=insert(temp->left,n);

	else if(new->data > temp->data)

		temp->right=insert(temp->right,n);

	else

	{

		printf("Element already exits");

		free(new);

	}

	return root;

}


struct node *delete(struct node *root,int m)

{

	struct node *pt,*temp,*fp,*l;

	temp=root;

	pt=NULL;

	while(temp!=NULL)

	{

		if(temp->data==m)

			break;

		else if(temp->data>m)

		{

			pt=temp;

			temp=temp->left;

		}

		else if(temp->data<m)

		{

			pt=temp;

			temp=temp->right;

		}

		else

		{

			printf("\nElement not found\n");

			return root;

		}

	}

	if(temp->left==NULL && temp->right==NULL)

		if(pt->left==temp)

		{

			free(temp);

			pt->left=NULL;

		}

		else

		{

			free(temp);

			pt->right=NULL;

		}

	else if(temp->left!=NULL && temp->right==NULL)

		if(pt->left==temp)

		{

			pt->left=temp->left;

			free(temp);

		}

		else

		{

			pt->right=temp->left;

			free(temp);

		}

	else if(temp->left==NULL && temp->right!=NULL)

		if(pt->left==temp)

		{

			pt->left=temp->right;

			free(temp);

		}

		else

		{

			pt->right=temp->right;

			free(temp);

		}

	else

	{

		l=temp->left;

		fp=NULL;

		while(l->right!=NULL)

		{

			fp=l;

			l=l->right;

		}

		temp->data=l->data;

		if(fp==NULL)

			temp->left=l->left;

		else

			fp->right=l->left;

		free(l);

	}

	return root;

}



void inorder(struct node *help_ptr)

{

	struct node *temp;

	temp=help_ptr;

	if(root==NULL)

	{

		printf("\nTree is empty\n");

		return;

	}

	if(temp!=NULL)

	{

		inorder(temp->left);

		printf("%d\t",temp->data);

		inorder(temp->right);

	}

	else

		return;

}

void preorder(struct node *help_ptr)

{

	struct node *temp;

	temp=help_ptr;

	if(root==NULL)

	{

		printf("\nTree is empty\n");

		return;

	}

	if(temp!=NULL)

	{

		printf("%d\t",temp->data);

		preorder(temp->left);

		preorder(temp->right);

	}

	else

		return;

}

void postorder(struct node *help_ptr)

{

	struct node *temp;

	temp=help_ptr;

	if(root==NULL)

	{

		printf("\nTree is empty\n");

		return;

	}

	if(temp!=NULL)

	{

		postorder(temp->left);

		postorder(temp->right);

		printf("%d\t",temp->data);

	}

	else

		return;

}

void main()

{

	int ch,n,m;

	do

	{

		printf("\n1.Insert\n2.Delete\n3.inorder\n4.preorder\n5.postorder\n6.Exit\n");
		printf("Enter your ch:");

		scanf("%d",&ch);

		switch(ch)

		{

			case 1:

				printf("Enter element to add\n");

				scanf("%d",&n);

				root=insert(root,n);

				break;

			case 2:

				if(root==NULL)

				{

					printf("\nTree is empty\n");

					break;

				}

				else

				{

					printf("Enter element to be deleted\n");

					scanf("%d",&m);

					root=delete(root,m);

					break;

				}

				break;

			case 3:

				inorder(root);

				break;

			case 4:

				preorder(root);

				break;

			case 5:

				postorder(root);

				break;

			case 6:

				printf("Exiting\n");

				break;

			default:

				printf("Incorrect choice");

				break;

		}

	}while(ch!=6);

}
