#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *left,*right;
};
typedef struct tree t;
void insert(t **root,int d)
{
	t *temp,*ptr,*save;
	temp=(t *)malloc(sizeof(t));
	temp->data=d;
	temp->left=temp->right=NULL;
	if((*root)==NULL)
	{
		(*root)->data=d;
		(*root)->left=(*root)->right=NULL;
		(*root)=temp;
	}
	else
	{
		ptr=(*root);
		while(ptr!=NULL)
		{
			save=ptr;
			if(ptr->data>d)
				ptr=ptr->left;
			else
				ptr=ptr->right;
		}
		if(d<(save->data))
			save->left=temp;
		else
			save->right=temp;
	}
}
void inorder(t *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",(root->data));
		inorder(root->right);
	}
}
void preorder(t *root)
{
	if(root!=NULL)
	{
		printf("%d\t",(root->data));
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(t *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",(root->data));
	}
}
void deletion(t **root,int val)
{
	char dir='0';
	t *par,*cur,*succ,*pred;
	cur=par=*root;
	while(1)
	{
		if(val<cur->data)
		{
			par=cur;
			cur=cur->left;
			dir='L';
		}
		else if(val>cur->data)
		{
			par=cur;
			cur=cur->right;
			dir='R';
		}
		else
		{
			if(cur->left==NULL && cur->right==NULL)
			{
				if(dir=='L')
					par->left=NULL;
				else
					par->right=NULL;
				break;
			}
			else if(cur->left!=NULL && cur->right!=NULL)
			{
				pred=cur->right;
				succ=cur->right;
				if(succ->left==NULL)
				{
					succ->left=cur->left;
					if(dir=='L')
						par->left=cur->right;
					else
						par->right=cur->right;
					break;
				}
				else
				{
					while(succ->left!=NULL)
					{
						pred=succ;
						succ=succ->left;
					}
					pred->left=succ->right;
					succ->left=cur->left;
					succ->right=cur->right;
					if(dir=='L')
						par->left=succ;
					else
						par->right=succ;
					break;
				}
			}
			else if(cur->left!=NULL && cur->right==NULL)
			{
				if(dir=='L')
					par->left=cur->left;
				else
					par->right=cur->left;
				break;
			}
			else if(cur->left==NULL && cur->right!=NULL)
			{
				if(dir=='L')
					par->left=cur->right;
				else
					par->right=cur->right;
				break;
			}
		 }
	}
	printf("Deleted Data = %d",cur->data);
}
void main()
{
	t *root=NULL;
	int d,a;
	printf("\t\t  1.Insert\n\
		  2.Inorder Traversal\n\
		  3.Preorder Traversal\n\
		  4.Postorder Traversal\n\
		  5.Delete\n\
		  6.Exit\n");
	start:
	printf("\nEnter Your choice:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			printf("Enter value=");
			scanf("%d",&d);
			insert(&root,d);
			printf("Inserted successfully!!!");
			getch();
			goto start;
		case 2:
			inorder(root);
			getch();
			goto start;
		case 3:
			preorder(root);
			getch();
			goto start;
		case 4:
			postorder(root);
			getch();
			goto start;
		case 5:
			printf("Enter value=");
			scanf("%d",&d);
			deletion(&root,d);
			getch();
			goto start;
		case 6:
			exit(0);
		default:
			printf("\nInvalid choice!!!");
			getch();
			goto start;
	}
}