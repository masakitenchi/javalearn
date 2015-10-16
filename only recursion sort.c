#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[10]={0};
void swap(int* m,int* n)
{
	int p;
	p=*m;
	*m=*n;
	*n=p;
	return ;
}
int Ack(int m,int n)
{
	if(m==0)
		return n+1;
	else if(n==0)
		return Ack(m-1,1);
	else
		return Ack(m-1,Ack(m,n-1));
}

int f1(int n)
{
	if(n==0)
		return a[0];
	else
		return f1(n-1)+a[n];
}

int f2(int n)
{
	if(n==0)
		return a[0];
	else
		return f2(n-1)>a[n]?f2(n-1):a[n];
}
/*
void f3(int n)
{
	int i;
	if(n==1)
		return ;
	for(i=0;i<n;i++)                                // for version
		if(a[i]<a[n])
			swap(&a[i],&a[n]);
	f3(n-1);
	return ;
}*/
void g(int n)
{
	int t;
	if(n>0)
	{
		g(n-1);
		if(a[n-1]<a[n])                             //only recursion version
			swap(&a[n-1],&a[n]);
	}
	return ;
}
void f3(int n)
{
	if(n>0)
	{
		g(n);
		f3(n-1);
	}
	return ;
}
int main()
{
	srand(time(0));
	int i;
	for(i=0;i<10;i++)
	{
		a[i]=rand()/20+1;
	}
	f3(10);
	printf("%d\n%d\n",f1(10),f2(10));
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
