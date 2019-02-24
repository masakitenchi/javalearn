#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	void quicksort(int*,int,int);
	int n,k,i,j;
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++)
		scanf("%d",s+i);
	quicksort(s,0,n);
	for(i=0;i<n;i++)
		printf("%d ",*(s+i));
	printf("\n");
	return 0;
}

void quicksort(int *s,int f,int b)
{
	if(f==b)
		return ;
	int i,j,k;
	
}