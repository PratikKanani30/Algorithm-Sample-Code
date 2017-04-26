#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct LL
{
	int data;
	struct LL *next;
};
typedef struct LL node;
void insert(node **t,int val)
{
	node *n=(node *)malloc(sizeof(node));
	node *temp=(*t);
	n->data=val;
	if((*t)==NULL)
		(*t)=n;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=n;
	n->next=NULL;
}
int delete(node **t)
{
	int val;
	node *temp=(*t);
	if((*t)==NULL)
		return -1;
	val=(*t)->data;
	(*t)=(*t)->next;
	free(temp);
	return val;
}
void traverse(node *t)
{
	if(t==NULL)
	{
		printf("Queue is empty!!");
		return;
	}
	printf("\n\nQueue = ");
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->next;
	}
}
void main()
{
	int a,val;
	node *t=NULL;
	label:
	clrscr();
	printf("\t\t\t1.INSERT\n\t\
		2.DELETE\n\t\
		3.TRAVERSE\n\t\
		4.EXIT\n\t\
		Enter Your Choice:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			printf("\n\n\tEnter the data=");
			scanf("%d",&val);
			insert(&t,val);
			printf("value is inserted successfully!!!");
			getch();
			goto label;
		case 2:
			val=delete(&t);
			printf("%d is deleted!!!",val);
			getch();
			goto label;
		case 3:
			traverse(t);
			getch();
			goto label;
		case 4:
			exit(0);
	}
}