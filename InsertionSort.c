#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 30000

void insertion_sort(int a[],int n)
{
	int j,temp,i;
	for(i=2;i<=n;i++)
	{
		temp=a[i];
		j=i-1;
		while(i>=1 && temp<a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
}

void main()
{
	int n,*a,i;
	clrscr();
	a=(int *)malloc(N*sizeof(int));
	clock_t s,e;
	randomize();
	for(i=0;i<N;i++)
		a[i]=rand()%10000;
	s=clock();
	insertion_sort(a,N);
	e=clock();
	for(i=0;i<N;i++)
		printf("\t%d",a[i]);
	printf("\n\n time=%f",(e-s)/CLK_TCK);
	getch();
}
