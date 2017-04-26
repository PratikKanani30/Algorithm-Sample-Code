#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 180
void merge(int a[], int low, int mid, int high)
{
	int *temp,i,j,k;
	temp=((int *)malloc(N*sizeof(int)));
	k = low;
	j = mid +1;
	i = low;
	while((k<=mid) && (j<=high))
	{       if(a[k]<=a[j])
		{       temp[i] = a[k] ;
			k++;
		}
		else
		{	temp[i] = a[j] ;
			j++;
		}
		i++;
	}
	if(k<=mid)
	    for(;k<=mid;k++)
		temp[i++] = a[k];
	else
	    for(;j<=high;j++)
		temp[i++]=a[j];
	for(i=low;i<=high;i++)a[i]=temp[i];
}
void merge_sort(int a[], int low, int high )
{
	int size,mid;
	size=high-low+1;
	if(size<=1)
	{
		return;
	}
	else
	{
		mid =low+(size/2)-1;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
		return;
	}
}
void main()
{
	int *a, i;
	clock_t x,y;
	a=((int *)malloc(N*sizeof(int)));
	randomize();
	for(i=0;i<N;i++)
		a[i]=rand()%100;
	x=clock();
	merge_sort(a,0,N-1);
	y=clock();
	printf("\n\nMerge sorted list is as follows:\n");
	for(i=0;i<N;i++)
		printf("%d  ",a[i]);
	printf("Time=%d",(y-x)*1000000/CLK_TCK);
	getch();
}


Output:
n=10  time=0.000000   b.c=0.000000 w.c=0.000000
n=100 time=0.000000   b.c=0.000000 w.c=0.000000
n=150 time=0.000000   b.c=0.000000 w.c=0.000000
n=160 time=0.000000   b.c=0.000000 w.c=0.000000
n=170 time=0.000000   b.c=0.000000 w.c=0.000000
n>170 "Stack Overflow!!"