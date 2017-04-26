#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 30000
void quick_sort(int a[],int first,int last)
{
	int temp, low, high, mid;
	low = first;
	high = last;
	mid = a[(first+last)/2];
	while (low <= high)
	{
		while (a[low]<mid)
			low++;
		while (a[high]>mid)
			high--;
		if (low<=high)
		{
			temp = a[low];
			a[low++] = a[high];
			a[high--] = temp;
		}
	}
	if (first<high)
		quick_sort(a,first,high);
	if (low<last)
		quick_sort(a,low,last);
}
void main()
{
	int *a,i,j;
	clock_t s,e;
	a=(int *)malloc(N*sizeof(int));
	randomize();
	for(i=0;i<N;i++)
		a[i]=rand()%10000;
	s=clock();
	quick_sort(a,0,N-1);
	e=clock();
	for(i=0;i<N;i++)
		printf("\t%d",a[i]);
	printf("\n\n time=%f",(e-s)/CLK_TCK);
	getch();
}

//n=1000  time=0.000000   b.c=0.000000 w.c=0.000000
//n=3000  time=0.000000   b.c=0.000000 w.c=0.000000
//n=5000  time=0.000000   b.c=0.000000 w.c=0.000000
//n=8000  time=0.000000   b.c=0.000000 w.c=0.000000
//n=10000 time=0.000000   b.c=0.000000 w.c=0.000000
//n=20000 time=0.000000   b.c=0.000000 w.c=0.000000
//n=30000 time=0.000000   b.c=0.000000 w.c=0.000000