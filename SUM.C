#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

unsigned long int sum(unsigned long int n)
{
	unsigned long int i,s=0;
	for(i=1;i<=n;i++)
	{
		s=s+i;
	}
	return s;

}

unsigned long int sum_1(unsigned long int n)
{
	unsigned long int a;
	a=n*(n+1)/2;
	return a;
}

unsigned long int sum_2(unsigned long int n)
{
	unsigned long int a=0;
	if(n<=0)
		return a;
	else
		a=n+sum_2(n-1);
	return a;
}

void main()
{
	clock_t a,b,c,d,e,f;
	unsigned long int n,s1,s2,s3;
	printf("\nenter value=");
	scanf("%lu",&n);
	a=clock();
	s1=sum(n);
	b=clock();
	printf("sum of 1st function=%lu",s1);
	printf("\ntime in millsecond=%f",(b-a)*1000/(CLK_TCK));
	c=clock();
	s2=sum_1(n);
	d=clock();
	printf("\nsum of 2st function=%lu",s2);
	printf("\ntime in millsecond=%f",(d-c)*1000/(CLK_TCK));
	e=clock();
	s3=sum_2(n);
	f=clock();
	printf("\nsum of 2st function=%lu",s3);
	printf("\ntime in millsecond=%f",(f-e)*1000/(CLK_TCK));
	getch();
}


Output:
enter value=100
sum of 1st function=5050
time in millsecond=0.000000
sum of 2nd function=5050
time in millsecond=0.000000
sum of 3rd function=5050
time in millsecond=0.000000

enter value=1000
sum of 1st function=500500
time in millsecond=0.000000
sum of 2nd function=500500
time in millsecond=0.000000
sum of 3rd function=500500
time in millsecond=0.000000

enter value=3000
sum of 1st function=4501500
time in millsecond=0.000000
sum of 2nd function=4501500
time in millsecond=0.000000
sum of 3rd function=4501500
time in millsecond=0.000000

enter value=5000
sum of 1st function=12502500
time in millsecond=0.000000
sum of 2nd function=12502500
time in millsecond=0.000000
sum of 3rd function=12502500
time in millsecond=0.000000

enter value=8000
sum of 1st function=32004000
time in millsecond=0.000000
sum of 2nd function=32004000
time in millsecond=0.000000
sum of 3rd function="stack overflow"
time in millsecond="-"

enter value=15000
sum of 1st function:112507500
time in millsecond=0.000000
sum of 2nd function:112507500
time in millsecond=0.000000
sum of 3rd function="stack overfow"
time in millsecond="-"

enter value=50000
sum of 1st function:1250025000
time in millsecond=0.000000
sum of 2nd function:1250025000
time in millsecond=0.000000
sum of 3rd function="stack overfow"
time in millsecond="-"

enter value=100000
sum of 1st function:705082704
time in millsecond=54.945055
sum of 2nd function:705082704
time in millsecond=0.000000
sum of 3rd function="stack overfow"
time in millsecond="-"