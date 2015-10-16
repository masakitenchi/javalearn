#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return 0;
	return 1;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=n/2;i<n;i++)
	{
		if(isprime(i))
			if(isprime(n-i))
			{
				printf("%d",i*(n-i));
				break;
			}
	}
	return 0;
}
