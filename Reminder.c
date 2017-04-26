#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

unsigned long int withmodulo(unsigned long int n1,unsigned long int n2)
{
	unsigned long int a;
	a=n1%n2;
	return a;
}

unsigned long int withoutmodulo(unsigned long int n1,unsigned long int n2)
{
	unsigned long int a;
	a=n1-n2*(n1/n2);
	return a;
}

void main()
{
	clock_t a,b,c,d;
	unsigned long int s1,x,y;
	printf("\nEnter Dividend=");
	scanf("%lu",&x);
	printf("Enter Divisor=");
	scanf("%lu",&y);
	a=clock();
	s1=withoutmodulo(x,y);
	b=clock();
	printf("remainder without modulo=%lu",s1);
	printf("\ntime in millisecond=%f",(b-
a)*1000/(CLK_TCK));
	c=clock();
	s1=withoutmodulo(x,y);
	d=clock();
	printf("\nremainder with modulo=%lu",s1);
	printf("\ntime in millisecond=%f",(d-
c)*1000/(CLK_TCK));
	getch();
}
