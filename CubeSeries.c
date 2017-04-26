#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>

unsigned long int series(unsigned long int n)
{
	unsigned long int s=0;
	s=(n*n*(n+1)*(n+1))/4;
	return s;
}

unsigned long int series2(unsigned long int n)
{
	unsigned long int i,s=0;
	if(n<=0)
		return(s);
	else
		s=(n*n*n)+series2(n-1);
	return s;
}

unsigned long int series1(unsigned long int n)
{
	unsigned long int i,s=0;
	for(i=1;i<=n;i++)
	{
		s=s+pow(i,3);
	}
	return s;
}

void main()
{
	clock_t a,b,c,d,e,f;
	unsigned long int s1,x;
	printf("\nEnter value=");
	scanf("%lu",&x);
	a=clock();
	s1=series(x);
	b=clock();
	printf("\nresult1=%lu",s1);
	printf("\ntime in millisecond for    
function1=%f",(b-a)*1000/(CLK_TCK));
	c=clock();
	s1=series1(x);
	d=clock();
	printf("\nresult2=%lu",s1);
	printf("\ntime in millisecond for 
function2=%f",(d-c)*1000/(CLK_TCK));
	e=clock();
	s1=series2(x);
	f=clock();
	printf("\nresult3=%lu",s1);
	printf("\ntime in millisecond for 
function3=%f",(f-e)*1000/(CLK_TCK));
	getch();
}
