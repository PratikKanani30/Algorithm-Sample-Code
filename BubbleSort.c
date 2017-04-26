#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 30000

void bubble_sort(int a[],int n)
{
	int last=n,p,exch,temp,i;
	for(p=0;p<=n-1;p++)
	{
		exch=0;
		for(i=0;i<last-1;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				exch++;
			}
		}
		if(exch==0)
			return;
		else
			last--;
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
	bubble_sort(a,N);
	e=clock();
	for(i=0;i<N;i++)
		printf("\t%d",a[i]);
	printf("\n\n time=%f",(e-s)/CLK_TCK);
	getch();
}
