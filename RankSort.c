#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 30000

void rank(int a[],int r[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		r[i]=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]<=a[i])
				r[i]++;
			else
				r[j]++;
		}
	}
}

void rank_sort(int a[],int r[],int n)
{
	int i,*temp;
	temp=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		temp[r[i]]=a[i];
	for(i=0;i<n;i++)
		a[i]=temp[i];
}

void main()
{
	int n,*a,*r,i,j;
	clrscr();
	a=(int *)malloc(N*sizeof(int));
	r=(int *)malloc(N*sizeof(int));
	clock_t s,e;
	randomize();
	for(i=0;i<N;i++)
		a[i]=rand()%10000;
	s=clock();
	rank(a,r,N);
	rank_sort(a,r,N);
	e=clock();
	for(i=0;i<N;i++)
		printf("\t%d",a[i]);
	printf("\n\n time=%f",(e-s)/CLK_TCK);
	getch();
}
