#include <stdio.h>
#define MAX 2147483647
int s[100];

void merge(int* t,int a,int b,int i)
{
	int m[50],n[50],j=0,f=0,l=0;
	for(j=a;j<=i;j++)
		m[j-a]=t[j];
	m[j-a]=MAX;
	for(j=i+1;j<=b;j++)
		n[j-i-1]=t[j];
	n[j-i-1]=MAX;
	j=0;
	do
	{
		s[j+a]=m[f]<n[l]?m[f++]:n[l++];
		j++;
	}while(j<b-a+1);
	return ;
}
void mergesort(int* t,int a,int b)
{
	int i;
	if(a>=b)
		return ;
	else
		i=(a+b)/2;
	mergesort(t,a,i);
	mergesort(t,i+1,b);
	merge(t,a,b,i);
	return ;
}
int main()
{
	int k,i,j;
	scanf("%d",&k);
	for(i=0;i<k;i++)
		scanf("%d",s+i);
	mergesort(s,0,k-1);
	for(i=0;i<k;i++)
		printf("%d ",*(s+i));
	printf("\n");
	return 0;
}