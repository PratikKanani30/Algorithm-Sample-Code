#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000

void selection_sort(int a[],int n)
{
	int p,min_ind,i,temp;
	for(p=0;p<=n-1;p++)
	{
		min_ind=p;
		for(i=p+1;i<n;i++)
		{
			if(a[i]<a[min_ind])
				min_ind=i;
		}
		if(min_ind!=p)
		{
			temp=a[min_ind];
			a[min_ind]=a[p];
			a[p]=temp;
		}
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
	selection_sort(a,N);
	e=clock();
	for(i=0;i<N;i++)
		printf("\t%d",a[i]);
	printf("\n\n time=%f",(e-s)/CLK_TCK);
	getch();
}
