#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
	int n;
	char a,b,c;
};
typedef struct node towernode;

void recursive_tower(int n,char a,char b,char c)
{
	if(n==1)
	{
	printf("%c-%c",a,c);
	return;
	}
	recursive_tower(n-1,a,c,b);
	printf("%c-%c , ",a,c);
	recursive_tower(n-1,b,a,c);
}

void iterative_tower(int n,char a,char b,char c)
{
	towernode stk[100];
	int sp=-1,temp,t;
	while(1)
	{
		if(n==1)
		{
			printf("%c-%c , ",a,c);
			if(sp==-1)
			break;
			else
			{
			n=stk[sp].n;
			a=stk[sp].a;
			b=stk[sp].b;
			c=stk[sp].c;
			sp--;
			printf("%c-%c , ",a,c);
			n--;
			temp=a;
			a=b;
			b=temp;
			}
		}

		else
		{
			sp++;
			stk[sp].n=n;
			stk[sp].a=a;
			stk[sp].b=b;
			stk[sp].c=c;
			n--;
			t=b;
			b=c;
			c=t;
		}
	}
}

void main()
{
	int n;
	clock_t a,b,c,d;
	printf("\nEnter no of disc=");
	scanf("%d",&n);
	printf("output of recursive function:\n");
	a=clock();
	recursive_tower(n,'a','b','c');
	b=clock();
	printf("\noutput of iterative function:\n");
	c=clock();
	iterative_tower(n,'a','b','c');
	d=clock();
	printf("\nTime for recousive function in milisecond= %f",(b-a)*1000/CLK_TCK);
	printf("\nTime for iterative function in milisecond= %f",(d-c)*1000/CLK_TCK);
	getch();
}

output:
Enter no of disc=2
output of recursive function:
a-b , a-c , b-c
output of iterative function:
a-b , a-c , b-c
Time for recousive function in milisecond=0.000000
Time for iterative function in milisecond=0.000000

Enter no of disc=3
output of recursive function:
a-c , a-b , c-b , a-c , b-a , b-c , a-c
output of iterative function:
a-c , a-b , c-b , a-c , b-a , b-c , a-c
Time for recousive function in milisecond=0.000000
Time for iterative function in milisecond=0.000000

Enter no of disc=4
output of recursive function:
a-b , a-c , b-c , a-b , c-a , c-b , a-b , a-c , b-c , b-a , c-a , b-c , a-b , a-c , b-c
output of iterative function:
a-b , a-c , b-c , a-b , c-a , c-b , a-b , a-c , b-c , b-a , c-a , b-c , a-b , a-c , b-c
Time for recousive function in milisecond=109.374784
Time for iterative function in milisecond=123.456782