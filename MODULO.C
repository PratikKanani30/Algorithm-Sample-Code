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
	printf("\ntime in milisecond=%f",(b-a)*1000/(CLK_TCK));
	c=clock();
	s1=withoutmodulo(x,y);
	d=clock();
	printf("\nremainder with modulo=%lu",s1);
	printf("\ntime in milisecond=%f",(d-c)*1000/(CLK_TCK));
	getch();
}

Output:
Enter Dividend=22345678
Enter Divisor=10
remainder without modulo=8
time in milisecond=0.000000
remainder with modulo=8
time in milisecond=0.000000

Enter Dividend=22345678
Enter Divisor=197
remainder without modulo=196
time in milisecond=0.000000
remainder with modulo=196
time in milisecond=0.000000

Enter Dividend=22345678
Enter Divisor=2345
remainder without modulo=678
time in milisecond=0.000000
remainder with modulo=678
time in milisecond=0.000000

Enter Dividend=22345678
Enter Divisor=23456
remainder without modulo=78
time in milisecond=0.000000
remainder with modulo=78
time in milisecond=0.000000

Enter Dividend=223456898
Enter Divisor=43256
remainder without modulo=33866
time in milisecond=0.000000
remainder with modulo=33866
time in milisecond=0.000000